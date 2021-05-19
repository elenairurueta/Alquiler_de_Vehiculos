#include "cTrafic.h"
string cTrafic::pasosMantenimiento = pasosMantenimientoMOTOCICLETA;

cTrafic::cTrafic(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad)
	:cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad)
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
