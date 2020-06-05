#include <iostream>
#include "Material.h"

using namespace std;

class Libro: public Material
{
  public:
  Libro();
  Libro(int, string, int, string);
  void setNumPag(int n) {numPag=(n>0 ? n : 0);};
  int getNumPag() {return numPag;};
  void setAutor(string a) {autor=a;};
  string getAutor() {return autor;};
  void muestraDatos();
  int cantidadDiasPrestamo();
  private:
  int numPag;
  string autor;
};
