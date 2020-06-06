#include <iostream>
#include <iomanip>
#include "Disco.h"

using namespace std;

Disco::Disco():Material()
{
  duracion=0;
  genero="Sin definir";
}

Disco::Disco(int i, string t, int d, string g): Material(i, t)
{

  duracion=(d>0 ? d : 0);
  genero=g;
}

void Disco::muestraDatos()
{
  cout << setw(15)<<"Disco"<< setw(10)<< idMaterial<< setw(15)<<duracion<< setw(20)<<genero<< setw(60)<<titulo << endl;
}

int Disco::cantidadDiasPrestamo()
{
  return 2;
}
