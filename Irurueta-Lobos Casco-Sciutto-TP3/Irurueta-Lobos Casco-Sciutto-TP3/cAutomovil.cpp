#include "cAutomovil.h"
cAutomovil::cAutomovil(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, string elementosSeguridad)
	:cVehiculo(numeroPatente,color,numeroChasis, numeroPoliza, ultimoMantenimiento, 
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, elementosSeguridad)
{
}
cAutomovil::~cAutomovil()
{

}
float cAutomovil::calcularTarifa(int cantDias)
{
	return (precioAlquilerXDia*cantDias + precioBase);
}
string cAutomovil::getTipoVehiculo()
{
	return "automovil";
}
