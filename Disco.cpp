#include <iostream>
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
  cout << "El disco con ID "<<idMaterial<<" se titula "<<titulo<<" tiene una duracion de "<<duracion<<" minutos y fue su genero es "<< genero <<"."<< endl;
}

int Disco::cantidadDiasPrestamo()
{
  return 2;
}
