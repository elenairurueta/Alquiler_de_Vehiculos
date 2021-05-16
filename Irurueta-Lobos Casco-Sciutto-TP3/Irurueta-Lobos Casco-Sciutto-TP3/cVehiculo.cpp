#include "cVehiculo.h"
int cVehiculo::precioBase = PRECIO_BASE;
cVehiculo::cVehiculo(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	unsigned int capacidadPasajeros, int cantElementosSeguridad, string elementosSeguridad)
	:numeroPatente(numeroPatente), color(color), numeroChasis(numeroChasis), numeroPoliza(numeroPoliza), capacidadPasajeros(capacidadPasajeros)
{
	this->ultimoMantenimiento = ultimoMantenimiento;
	this->precioAlquilerXDia = precioAlquilerXDia;
	this->cantElementosSeguridad = cantElementosSeguridad;
	this->elementosSeguridad = elementosSeguridad;
}

cVehiculo::~cVehiculo()
{
	if (ultimoMantenimiento != NULL)
		delete ultimoMantenimiento;
}

unsigned int cVehiculo::getclave()
{
	return numeroPatente;
}

void cVehiculo::setPrecioBase(float precio)
{
	precioBase = precio;
}

