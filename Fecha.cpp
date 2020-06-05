#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
  dd=0;
  mm=0;
  aa=0;
}

Fecha::Fecha(int d, int m, int a)
{
  dd=(d>0 ? d : 0);
  mm=(m>0 ? m : 0);
  aa=(a>0 ? a : 0);
}

void Fecha::setFecha(int d, int m, int a)
{
  dd=(d>0 ? d : 0);
  mm=(m>0 ? m : 0);
  aa=(a>0 ? a : 0);
}

Fecha Fecha::operator+(int d)
{
  int dia=dd;
  int mes=mm;
  int anio=aa;

  dia = dd + d;

  if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10)
  {
    if(dia>31)
    {
      dia=dia-31;
      mes++;
    }
  }
  else if(mm==12)
  {
    if(dia>31)
    {
      dia=dia-31;
      mes=1;
      anio++;
    }
  }
  else if(mm==4 || mm==6 || mm==9 || mm==11)
  {
    if(dia>30)
    {
      dia=dia-30;
      mes++;
    }
  }
  else if(mm==2)
  {
    int bisiesto=aa%4;
    if(bisiesto==0)
    {
      dia=dia-29;
      mes++;
    }
    else
    {
      dia=dia-28;
      mes++;
    }
  }

  Fecha f2(dia, mes, anio);
  return f2;
}

bool Fecha::operator>(Fecha f2)
{
  if(aa<f2.aa)
  {
    return false;
  }
  else if(aa>f2.aa)
  {
    return true;
  }
  else if(aa==f2.aa)
  {
    if(mm<f2.mm)
    {
      return false;
    }
    else if(mm>f2.mm)
    {
      return true;
    }
    else if(mm==f2.mm)
    {
      if(dd<f2.dd)
      {
        return false;
      }
      else if(dd>f2.dd)
      {
        return true;
      }
      else if(dd==f2.dd)
      {
        return false;
      }
    }
  }
}

bool Fecha::operator>=(Fecha f2)
{
  if(aa<f2.aa)
  {
    return false;
  }
  else if(aa>f2.aa)
  {
    return true;
  }
  else if(aa==f2.aa)
  {
    if(mm<f2.mm)
    {
      return false;
    }
    else if(mm>f2.mm)
    {
      return true;
    }
    else if(mm==f2.mm)
    {
      if(dd<f2.dd)
      {
        return false;
      }
      else if(dd>f2.dd)
      {
        return true;
      }
      else if(dd==f2.dd)
      {
        return true;
      }
    }
  }
}

bool Fecha::operator<(Fecha f2)
{
  if(aa<f2.aa)
  {
    return true;
  }
  else if(aa>f2.aa)
  {
    return false;
  }
  else if(aa==f2.aa)
  {
    if(mm<f2.mm)
    {
      return true;
    }
    else if(mm>f2.mm)
    {
      return false;
    }
    else if(mm==f2.mm)
    {
      if(dd<f2.dd)
      {
        return true;
      }
      else if(dd>f2.dd)
      {
        return false;
      }
      else if(dd==f2.dd)
      {
        return false;
      }
    }
  }
}

bool Fecha::operator<=(Fecha f2)
{
  if(aa<f2.aa)
  {
    return true;
  }
  else if(aa>f2.aa)
  {
    return false;
  }
  else if(aa==f2.aa)
  {
    if(mm<f2.mm)
    {
      return true;
    }
    else if(mm>f2.mm)
    {
      return false;
    }
    else if(mm==f2.mm)
    {
      if(dd<f2.dd)
      {
        return true;
      }
      else if(dd>f2.dd)
      {
        return false;
      }
      else if(dd==f2.dd)
      {
        return true;
      }
    }
  }
}

bool Fecha::operator==(Fecha f2)
{
  if(aa==f2.aa)
  {
    if(mm==f2.mm)
    {
      if(dd==f2.dd)
      {
        return true;
      }
    }
  }
  
  return false;
  
}

ostream &operator<<(ostream &os, const Fecha &f)
{
  string mes;
  if(f.mm==1)
  {
    mes="Ene";
  }
  else if(f.mm==2)
  {
    mes="Feb";
  }
  else if(f.mm==3)
  {
    mes="Mar";
  }
  else if(f.mm==4)
  {
    mes="Abr";
  }
  else if(f.mm==5)
  {
    mes="May";
  }
  else if(f.mm==6)
  {
    mes="Jun";
  }
  else if(f.mm==7)
  {
    mes="Jul";
  }
  else if(f.mm==8)
  {
    mes="Ago";
  }
  else if(f.mm==9)
  {
    mes="Sep";
  }
  else if(f.mm==10)
  {
    mes="Oct";
  }
  else if(f.mm==11)
  {
    mes="Nov";
  }
  else if(f.mm==12)
  {
    mes="Dec";
  }
  os<<f.dd<<" "<<mes<<" "<<f.aa<< endl;
  return os;
}

istream &operator>>(istream &is, Fecha &f)
{
  string mes;
  if(f.mm==1)
  {
    mes="Ene";
  }
  else if(f.mm==2)
  {
    mes="Feb";
  }
  else if(f.mm==3)
  {
    mes="Mar";
  }
  else if(f.mm==4)
  {
    mes="Abr";
  }
  else if(f.mm==5)
  {
    mes="May";
  }
  else if(f.mm==6)
  {
    mes="Jun";
  }
  else if(f.mm==7)
  {
    mes="Jul";
  }
  else if(f.mm==8)
  {
    mes="Ago";
  }
  else if(f.mm==9)
  {
    mes="Sep";
  }
  else if(f.mm==10)
  {
    mes="Oct";
  }
  else if(f.mm==11)
  {
    mes="Nov";
  }
  else if(f.mm==12)
  {
    mes="Dec";
  }
  is >> f.dd >> f.mm >>f.aa;
  return is;
}
