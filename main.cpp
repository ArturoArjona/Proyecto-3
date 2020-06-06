#include <iostream>
#include <iomanip>
#include <fstream>
#include "Reserva.h"
#include "Software.h"

using namespace std;

int main() 
{
  Material *arrMat[30];
  Reserva arrRes[60];
  Libro arrL[30];
  Disco arrD[30];
  Software arrS[30];
  ifstream matEnt;
  matEnt.open("Material.txt");
  int cont=0;
  int im;
  string tl;
  char cl;
  int dat;
  string adt;
  while (matEnt >> im >> tl >> cl>> dat>>adt)
  {
    if(cl=='L')
    {
      arrL[cont].setIdMaterial(im);
      arrL[cont].setTitulo(tl);
      arrL[cont].setNumPag(dat);
      arrL[cont].setAutor(adt);
      arrMat[cont]=&arrL[cont];
    }
    else if(cl=='D')
    {
      arrD[cont].setIdMaterial(im);
      arrD[cont].setTitulo(tl);
      arrD[cont].setDuracion(dat);
      arrD[cont].setGenero(adt);
      arrMat[cont]=&arrD[cont];
    }
    else if(cl=='S')
    {
      arrS[cont].setIdMaterial(im);
      arrS[cont].setTitulo(tl);
      arrS[cont].setVersion(dat);
      arrS[cont].setSo(adt);
      arrMat[cont]=&arrS[cont];
    }
    cont++;
  }
  matEnt.close();


  ifstream resEnt;
  resEnt.open("Reserva.txt");
  int cnt=0;
  int d, m, a, imt, ic;
  while (resEnt >> d >> m >> a >> imt >> ic)
  {
    Fecha ftemp(d,m,a);
    arrRes[cnt].setIdMaterial(imt);
    arrRes[cnt].setIdCliente(ic);
    arrRes[cnt].setFechaReservacion(ftemp);
    cnt++;
  }
  resEnt.close();


  int menu=0;
  do 
  {
    cout << endl;
    cout << "Seleccione la opcion que desea realizar:" << endl;
    cout << "1: Consultar la lista de materiales." << endl;
    cout << "2: Consultar la lista de reservaciones." << endl;
    cout << "3: Consultar las reservaciones de un material." << endl;
    cout << "4: Consultar las reservaciones de una fecha." << endl;
    cout << "5: Hacer reservacion." << endl;
    cout << "6: Terminar." << endl;
    cin >> menu;

    if(menu==1)
    {
      cout << setw(15)<<"Tipo"<< setw(10)<< "ID"<< setw(15)<<"NumPg/Dur/Ver"<< setw(20)<<"Autor/Genero/SO"<< setw(60)<<"Titulo" << endl;
      for(int print=0; print < cont; print++)
      {
        arrMat[print]->muestraDatos();
        cout << endl;
      }
    }
    else if(menu==2)
    {
      cout << setw(60)<<"Titulo"<< setw(20)<<"Fecha de inicio"<< setw(20)<<"Fecha de termino"<<endl;
      for(int print=0; print < cnt; print++)
      {
        bool a=false;
        int comp=0;
        int found;
        while(a==false)
        {
          if(arrRes[print].getIdMaterial()==arrMat[comp]->getIdMaterial())
          {
            cout << setw(40)<< arrMat[comp]->getTitulo();
            found=comp;
            a=true;
          }
          comp++;
        }
        Fecha fdt;
        fdt=arrRes[print].getFechaReservacion()+arrMat[found]->cantidadDiasPrestamo();
        cout<< setw(20)<< arrRes[print].getFechaReservacion();
        cout<< setw(20)<< fdt;
        cout << endl;
      }
    }
    else if(menu==3)
    {
      bool fd=false;
      int idm;
      int pos;
      do
      {
        cout << "Cual es el ID del material que desea revisar?" << endl;
        cin >> idm;
        for(int x=0; x<cont; x++)
        {
          if(idm==arrMat[x]->getIdMaterial())
          {
            pos=x;
            fd=true;
          }
        }
        if(fd==false)
        {
          cout << "El ID introducida no es valido." << endl;
        }
      }while(fd==false);

      cout << setw(60)<<"Titulo"<< setw(20)<<"Fecha de inicio"<< setw(20)<<"Fecha de termino"<<endl;

      for(int print=0; print < cnt; print++)
      {
        if(idm==arrRes[print].getIdMaterial())
        {
          cout << setw(40)<< arrMat[pos]->getTitulo();
          Fecha fdt;
          fdt=arrRes[print].getFechaReservacion()+arrMat[pos]->cantidadDiasPrestamo();
          cout<< setw(20)<< arrRes[print].getFechaReservacion();
          cout<< setw(20)<< fdt;
          cout << endl;
        }
      }
    }
    else if(menu==4)
    {
      int dia, mes, anio;
      cout << "Cual es la fecha que desea revisar?(dd mm aaaa)" << endl;
      cin >> dia >> mes >> anio;

      cout << setw(60)<<"Titulo"<< setw(20)<<" ID Cliente"<<endl;
      Fecha fcom1;
      Fecha fcom2;
      Fecha f2(dia, mes, anio);
      for(int z=0; z< cnt; z++)
      {
        fcom1=arrRes[z].getFechaReservacion();
        if(f2>=fcom1)
        {
          bool a=false;
          int comp=0;
          int fd;
          while(a==false)
          {
            if(arrRes[z].getIdMaterial()==arrMat[comp]->getIdMaterial())
            {
              fd=comp;
              a=true;
            }
            comp++;
          }
          fcom2=fcom1+arrMat[fd]->cantidadDiasPrestamo();
          if(f2<=fcom2)
          {
            cout << setw(40)<< arrMat[fd]->getTitulo();
            cout << setw(20)<< arrRes[z].getIdCliente();
          }

          cout << endl;
        }
      }
    }
    else if(menu==5)
    {
      int idc;
      cout << "Cual es su ID?" << endl;
      cin >> idc;

      bool id=false;
      int idm;
      int pos;
      do
      {
        cout << "Cual es el ID material que desea reservar?" << endl;
        cin >> idm;
        for(int x=0; x<cont; x++)
        {
          if(idm==arrMat[x]->getIdMaterial())
          {
            pos=x;
            id=true;
          }
        }
        if(id==false)
        {
          cout << "El ID introducido no es valido." << endl;
        }
      }while(id==false);

      int dia, mes, anio;
      cout << "Cual es la fecha que desea revisar?(dd mm aaaa)" << endl;
      cin >> dia >> mes >> anio;


      bool reservar=true;
      Fecha fcom1;
      Fecha fcom2;
      Fecha f2(dia, mes, anio);
      for(int z=0; z< cnt; z++)
      {
        if (idm==arrRes[z].getIdMaterial())
        {
          fcom1=arrRes[z].getFechaReservacion();
          fcom2=arrRes[z].getFechaReservacion() + arrMat[pos]->cantidadDiasPrestamo();
          if(f2>=fcom1 && f2<=fcom2)
          {
            reservar=false;
          }
        }
      }
      if (reservar==false)
      {
        cout<<"No es posible reservar en esta fecha."<< endl;
      }
      else
      {
        arrRes[cnt].setIdMaterial(idm);
        arrRes[cnt].setIdCliente(idc);
        arrRes[cnt].setFechaReservacion(f2);
        cnt++;
        cout<<"El material fue reservado."<< endl;
      }
      
      
    }
    else if (menu==6)
    {
      cout << "Hasta luego" << endl;
    }
    else
    {
      cout << "Esta opcion no existe." << endl;
    }
  } while (menu != 6);

  return 0;
}
