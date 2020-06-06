#include <iostream>
#include <iomanip>
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
  cout << setw(15)<<"Software"<< setw(10)<< idMaterial<< setw(15)<<version<< setw(20)<<so<< setw(60)<<titulo << endl;
}

int Software::cantidadDiasPrestamo()
{
  return 1;
}
