#include "cMotocicleta.h"

cMotocicleta::cMotocicleta(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, string elementosSeguridad)
	:cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, elementosSeguridad)
{
}
cMotocicleta::~cMotocicleta()
{
}

string cMotocicleta::getTipoVehiculo()
{
	return "motocicleta";
}

float cMotocicleta::calcularTarifa(int cantDias)
{
	return (precioAlquilerXDia*cantDias + precioBase);
}
