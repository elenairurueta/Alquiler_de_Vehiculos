#include "cCamioneta.h"
cCamioneta::cCamioneta():cVehiculo()
{
	precioAlquilerXDia = ALQUILER_CAMIONETAS;
}
cCamioneta::~cCamioneta()
{
}

string cCamioneta::getTipoVehiculo()
{
	return "camioneta";
}

float cCamioneta::calcularTarifa(int cantDias)
{
	return (precioAlquilerXDia*cantDias + precioBase);
}
