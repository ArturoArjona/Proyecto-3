#include <iostream>
#include "Reserva.h"

using namespace std;

Reserva::Reserva()
{
  Fecha f1;
  idMaterial=0;
  idCliente=0;
  fechaReservacion=f1;
}

Reserva::Reserva(int im, int ic, Fecha f1)
{
  idMaterial=im;
  idCliente=ic;
  fechaReservacion=f1;
}

Fecha Reserva::calculaFechaFinReserva(int d)
{
  Fecha ffr;
  ffr=fechaReservacion+d;
  return ffr;
}
