#include <iostream>

using namespace std;

class Fecha
{
  public:
  Fecha();
  Fecha(int, int, int);
  int getDia() {return dd;};
  int getMes() {return mm;};
  int getAa() {return aa;};
  void setFecha(int d, int m, int a);
  Fecha operator+(int);
  bool operator>(Fecha f2);
  bool operator>=(Fecha f2);
  bool operator<(Fecha f2);
  bool operator<=(Fecha f2);
  bool operator==(Fecha f2);
  friend ostream &operator<<(ostream &os, const Fecha &f);
  friend istream &operator>>(istream &is, Fecha &f);
  private:
  int dd, mm, aa;
};
