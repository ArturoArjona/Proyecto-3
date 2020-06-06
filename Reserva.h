#include <iostream>
#include "Fecha.h"

using namespace std;

class Reserva
{
  public:
  Reserva();
  Reserva(int, int, Fecha);
  void setIdMaterial(int im) {idMaterial=(im>=0 ? im : 0);};
  int getIdMaterial() {return idMaterial;};
  void setIdCliente(int ic) {idCliente=(ic>=0 ? ic : 0);};
  int getIdCliente() {return idCliente;};
  void setFechaReservacion(Fecha fr) {fechaReservacion=fr;};
  Fecha getFechaReservacion() {return fechaReservacion;};
  Fecha calculaFechaFinReserva(int);
  private:
  int idMaterial, idCliente;
  Fecha fechaReservacion;
};
