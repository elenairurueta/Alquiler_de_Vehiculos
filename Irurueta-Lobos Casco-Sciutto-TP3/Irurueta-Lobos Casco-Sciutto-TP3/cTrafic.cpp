#include "cTrafic.h"
string cTrafic::pasosMantenimiento = pasosMantenimientoMOTOCICLETA;

cTrafic::cTrafic(string numeroPatente, unsigned int color, string numeroChasis,
	string numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, float precioVehiculo)
	:cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, precioVehiculo)
{
}

cTrafic::~cTrafic()
{
}

string cTrafic::getTipoVehiculo()
{
	return "trafic";
}
string cTrafic::getPasosMantenimiento()
{
	return pasosMantenimiento;
}
