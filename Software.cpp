#include <iostream>
#include "Software.h"

using namespace std;

Software::Software():Material()
{
  version=0;
  so="Sin definir";
}

Software::Software(int i, string t, int v, string s):Material(i, t)
{
  version=(v>0 ? v : 0);
  so=s;
}

void Software::muestraDatos()
{
  cout << "El software con ID "<<idMaterial<<" se titula "<<titulo<<" su version es "<<version<<" y el sistema operativo en el que corre es "<< so <<"."<< endl;
}

int Software::cantidadDiasPrestamo()
{
  return 1;
}
