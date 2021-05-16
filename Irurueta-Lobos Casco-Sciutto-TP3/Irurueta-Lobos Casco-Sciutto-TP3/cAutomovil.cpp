#include "cAutomovil.h"
cAutomovil::cAutomovil() :cVehiculo()
{
	precioAlquilerXDia = ALQUILER_AUTOMOVILES;
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
