#include <iostream>
#include "Material.h"

using namespace std;

class Software: public Material
{
  public:
  Software();
  Software(int, string, int, string);
  void setVersion(int v) {version=(v>0 ? v : 0);};
  int getVersion() {return version;};
  void setSo(string s) {so=s;};
  string getSo() {return so;};
  void muestraDatos();
  int cantidadDiasPrestamo();
  private:
  int version;
  string so;
};
