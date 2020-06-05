#include <iostream>
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
  cout << "El libro con ID "<<idMaterial<<" se titula "<<titulo<<" contiene "<<numPag<<" paginas y fue escrito por "<< autor <<"."<< endl;
}

int Libro::cantidadDiasPrestamo()
{
  return 7;
}
