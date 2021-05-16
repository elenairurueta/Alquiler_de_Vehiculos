#include "cTrafic.h"

cTrafic::cTrafic():cVehiculo()
{
	precioAlquilerXDia = ALQUILER_TRAFICS;
}

cTrafic::~cTrafic()
{
}

string cTrafic::getTipoVehiculo()
{
	return "trafic";
}

float cTrafic::calcularTarifa()
{
	return (precioAlquilerXDia + precioBase);
}
