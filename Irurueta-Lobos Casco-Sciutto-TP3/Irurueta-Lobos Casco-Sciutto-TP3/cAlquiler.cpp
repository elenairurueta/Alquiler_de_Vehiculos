#include "cAlquiler.h"
int cAlquiler::cantAlquileres = 0;
cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, 
	int cantElementosSeguridad, cFecha fechaInicioReserva, 
	cFecha fechaFinReserva, float montoTotal):codigoReserva(cantAlquileres++)
{
	fechaInicioReserva.actualizarFecha();
	this->cliente = cliente;
	this->vehiculo = vehiculo;
	this->cantElementosSeguridad = cantElementosSeguridad;
	this->fechaInicioReserva = fechaInicioReserva;
	this->fechaFinReserva = fechaFinReserva;
	this->montoTotal = montoTotal;
}

cAlquiler::~cAlquiler()
{
}

int cAlquiler::getClave()const
{
	return codigoReserva;
}
