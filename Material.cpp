#include <iostream>
#include "Material.h"

using namespace std;

Material::Material()
{
  idMaterial=0;
  titulo="Sin Definir";
}

Material::Material(int i, string t)
{
  idMaterial=(i>=0 ? i : 0);
  titulo=t;
}
