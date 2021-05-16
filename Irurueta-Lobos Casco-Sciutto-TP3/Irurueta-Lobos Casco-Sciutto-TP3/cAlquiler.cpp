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

string cAlquiler::getclave()const
{
	return to_string(codigoReserva);
}

string cAlquiler::toString()
{
	string cadena = "Codigo de Reserva: " + to_string(codigoReserva) + "\nCliente: " + cliente->toString() + "\nVehiculo: " + vehiculo->getTipoVehiculo() + vehiculo->toString();
	cadena += "\nFecha inicio: " + fechaInicioReserva.toString() + "\nFecha Fin: " + fechaFinReserva.toString() + "\nElementos de Seguridad: " + to_string(cantElementosSeguridad) + "Monto total: " + to_string(montoTotal);
	return cadena;
}
ostream& operator<<(ostream& os, cAlquiler* alquiler)
{
	os << alquiler->toString();
	return os;
}
