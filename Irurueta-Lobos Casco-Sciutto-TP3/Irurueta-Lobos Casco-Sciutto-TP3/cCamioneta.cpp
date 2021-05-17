#include "cCamioneta.h"
cCamioneta::cCamioneta(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, string elementosSeguridad)
	: cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, elementosSeguridad)
{
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
