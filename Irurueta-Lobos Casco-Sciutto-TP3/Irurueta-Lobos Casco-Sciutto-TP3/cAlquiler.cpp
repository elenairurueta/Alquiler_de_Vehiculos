#include "cAlquiler.h"
int cAlquiler::cantAlquileres = 0;
cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, 
	int cantElementosSeguridad, cFecha fechaInicioReserva, 
	cFecha fechaFinReserva, float montoTotal):codigoReserva(cantAlquileres++)
{
	cFecha *auxiliar = new cFecha();
	if (fechaInicioReserva.compararFechas(auxiliar) == 0)
		fechaInicioReserva.actualizarFecha();
	delete auxiliar;
	this->fechaInicioReserva = fechaInicioReserva;
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
	string cadena = "Codigo de Reserva: " + to_string(codigoReserva);
	if (cliente != NULL)
		cadena += "\nCliente: " + cliente->toString(); 
	if (vehiculo != NULL)
		cadena += "\nVehiculo: " + vehiculo->getTipoVehiculo() + vehiculo->toString();
	cadena += "\nFecha inicio: " + fechaInicioReserva.toString() + "\nFecha Fin: ";
	
	cFecha* auxiliar = new cFecha();
	if (fechaFinReserva.compararFechas(auxiliar) == 0)
		cadena += "No definida";
	else
		cadena += fechaFinReserva.toString();
	delete auxiliar;

	cadena += "\nElementos de Seguridad: " + to_string(cantElementosSeguridad) + "\nMonto total: " + to_string(montoTotal);
	return cadena;
}
ostream& operator<<(ostream& os, cAlquiler* alquiler)
{
	if (alquiler == NULL)
		return os;
	os << alquiler->toString();
	return os;
}
