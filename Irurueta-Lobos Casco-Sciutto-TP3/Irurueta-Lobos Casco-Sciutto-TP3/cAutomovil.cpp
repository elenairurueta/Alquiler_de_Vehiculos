#include "cAutomovil.h"
string cAutomovil::pasosMantenimiento = pasosMantenimientoAUTOMOVIL;

cAutomovil::cAutomovil(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, float precioVehiculo)
	:cVehiculo(numeroPatente,color,numeroChasis, numeroPoliza, ultimoMantenimiento, 
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, precioVehiculo)
{
}
cAutomovil::~cAutomovil()
{

}
string cAutomovil::getTipoVehiculo()
{
	return "automovil";
}
string cAutomovil::getPasosMantenimiento()
{
	return pasosMantenimiento;
}
