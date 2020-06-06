#include <iostream>
#include <iomanip>
#include "Libro.h"

using namespace std;

Libro::Libro():Material()
{
  numPag=0;
  autor="John Doe";
}

Libro::Libro(int i, string t, int n, string a):Material(i, t)
{
  numPag=(n>0 ? n : 0);
  autor=a;
}

void Libro::muestraDatos()
{
  cout << setw(15)<<"Libro"<< setw(10)<< idMaterial<< setw(15)<<numPag<< setw(20)<<autor<< setw(60)<<titulo << endl;
}

int Libro::cantidadDiasPrestamo()
{
  return 7;
}
