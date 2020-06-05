#include <iostream>

using namespace std;

class Material
{
  public:
  Material();
  Material(int, string);
  void setIdMaterial(int i) {idMaterial=(i>=0 ? i : 0);};
  int getIdMaterial() {return idMaterial;};
  void setTitulo(string t) {titulo=t;};
  string getTitulo() {return titulo;};
  virtual void muestraDatos() = 0;
  virtual int cantidadDiasPrestamo() = 0;
  protected:
  int idMaterial;
  string titulo;
};
