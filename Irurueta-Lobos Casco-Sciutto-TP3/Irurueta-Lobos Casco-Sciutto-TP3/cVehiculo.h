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
	const int cantElementosSeguridad;

public:
	cVehiculo(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0, 
		unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = 0,
		const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = 0);
	virtual ~cVehiculo();
	virtual float calcularTarifa(int cantDias) = 0;
	string getclave()const;
	virtual string getTipoVehiculo() = 0;
	void setPrecioBase(float precio);
	string toString(string separador = "\n")const;
	virtual int getCantidadElementosSeguridad() = 0;
};
ostream& operator<<(ostream& out, const cVehiculo* vehiculo);
