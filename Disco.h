#include <iostream>
#include "Material.h"

using namespace std;

class Disco: public Material
{
  public:
  Disco();
  Disco(int, string, int, string);
  void setDuracion(int d) {duracion=(d>0 ? d : 0);};
  int getDuracion() {return duracion;};
  void setGenero(string g) {genero=g;};
  string getGenero() {return genero;};
  void muestraDatos();
  int cantidadDiasPrestamo();
  private:
  int duracion;
  string genero;
};
