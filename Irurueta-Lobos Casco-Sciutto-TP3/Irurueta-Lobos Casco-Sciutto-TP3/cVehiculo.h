#pragma once
#include "cFecha.h"
#include "defines.h"
#define PRECIO_BASE 100
typedef enum {AMARILLO, LILA, DORADO, FUCSIA, VERDE}color;
class cVehiculo
{
protected:
	const unsigned int numeroPatente;
	const unsigned int color;
	const unsigned int numeroChasis;
	const unsigned int numeroPoliza;
	cFecha* ultimoMantenimiento;
	float precioAlquilerXDia;
	static int precioBase;
	const unsigned int capacidadPasajeros;
	int cantElementosSeguridad;
	string elementosSeguridad; //T*?

public:
	cVehiculo(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0, 
		unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = 0,
		const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = 0, string elementosSeguridad = "");
	virtual ~cVehiculo();
	virtual float calcularTarifa() = 0;
	unsigned int getclave();
	virtual string getTipoVehiculo() = 0;
	void setPrecioBase(float precio);
};