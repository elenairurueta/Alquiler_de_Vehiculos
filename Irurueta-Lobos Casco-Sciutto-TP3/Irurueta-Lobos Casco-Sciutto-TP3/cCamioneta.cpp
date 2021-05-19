#include "cCamioneta.h"
string cCamioneta::pasosMantenimiento = pasosMantenimientoCAMIONETA;

cCamioneta::cCamioneta(string numeroPatente, unsigned int color, string numeroChasis,
	string numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, float precioVehiculo)
	: cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, precioVehiculo)
{
}
cCamioneta::~cCamioneta()
{
}

string cCamioneta::getTipoVehiculo()
{
	return "camioneta";
}

string cCamioneta::getPasosMantenimiento()
{
	return pasosMantenimiento;
}
