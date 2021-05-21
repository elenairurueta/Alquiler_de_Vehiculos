#include "cAutomovil.h"
string cAutomovil::pasosMantenimiento = pasosMantenimientoAUTOMOVIL; //inicialización atributo static

#pragma region Constructor y Destructor
cAutomovil::cAutomovil(string numeroPatente, unsigned int color, string numeroChasis,
	string numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	const unsigned int capacidadPasajeros, int cantElementosSeguridad, float precioVehiculo)
	:cVehiculo(numeroPatente,color,numeroChasis, numeroPoliza, ultimoMantenimiento, 
		precioAlquilerXDia, capacidadPasajeros, cantElementosSeguridad, precioVehiculo)
{
}
cAutomovil::~cAutomovil()
{

}
#pragma endregion

#pragma region Getters
string cAutomovil::getTipoVehiculo()
{
	return "automovil";
}
string cAutomovil::getPasosMantenimiento()
{
	return pasosMantenimiento;
}
#pragma endregion
