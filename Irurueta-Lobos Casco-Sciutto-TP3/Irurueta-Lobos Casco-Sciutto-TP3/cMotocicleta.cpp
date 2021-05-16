#include "cMotocicleta.h"

cMotocicleta::cMotocicleta():cVehiculo()
{
	precioAlquilerXDia = ALQUILER_MOTOCICLETAS;
}
cMotocicleta::~cMotocicleta()
{
}

string cMotocicleta::getTipoVehiculo()
{
	return "motocicleta";
}

float cMotocicleta::calcularTarifa()
{
	return (precioAlquilerXDia + precioBase);
}
