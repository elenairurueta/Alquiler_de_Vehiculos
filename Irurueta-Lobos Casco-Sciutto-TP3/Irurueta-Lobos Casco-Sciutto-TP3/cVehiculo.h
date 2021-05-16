#pragma once
#include "cFecha.h"

class cVehiculo
{
protected:
	const unsigned int numeroPatente;
	const unsigned int color;
	const unsigned int numeroChasis;
	const unsigned int numeroPoliza;
	cFecha* ultimoMantenimiento;
	float precioAlquilerXDia;
	const unsigned int capacidadPasajeros;
	int cantElementosSeguridad;
	string elementosSeguridad; //T*?

public:
	cVehiculo();
	virtual ~cVehiculo();
	virtual float calcularTarifa() = 0;
	unsigned int getclave();

};