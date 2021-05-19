#include "cCamioneta.h"
cCamioneta::cCamioneta(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, const string pasosMantenimiento)
	: cVehiculo(numeroPatente, color, numeroChasis, numeroPoliza, ultimoMantenimiento,
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, pasosMantenimiento)
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

int cCamioneta::getCantidadElementosSeguridad()
{
	return cantElementosSeguridad;
}
