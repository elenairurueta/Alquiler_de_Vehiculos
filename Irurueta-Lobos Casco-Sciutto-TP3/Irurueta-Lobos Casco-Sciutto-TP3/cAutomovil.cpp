#include "cAutomovil.h"

cAutomovil::~cAutomovil()
{

}
cAutomovil::cAutomovil():cVehiculo()
{
	precioAlquilerXDia = ALQUILER_AUTOMOVILES;
}
float cAutomovil::calcularTarifa()
{
	return (precioAlquilerXDia + precioBase);
}
string cAutomovil::getTipoVehiculo()
{
	return "automovil";
}
