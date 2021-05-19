#pragma once
#include "cFecha.h"
#include "defines.h"
#define PRECIO_BASE 100
typedef enum {AMARILLO, LILA, DORADO, FUCSIA, VERDE}color;
class cVehiculo
{
protected:
	const string numeroPatente;
	const unsigned int color;
	const string numeroChasis;
	const string numeroPoliza;
	cFecha* ultimoMantenimiento;
	float precioAlquilerXDia;
	static int precioBase;
	const float precioVehiculo;
	const unsigned int capacidadPasajeros;
	const int cantElementosSeguridad;

public:
	cVehiculo(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
		string numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = 0,
		const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = 0, const float precioVehiculo = 0);
	virtual ~cVehiculo();
	float calcularTarifa(int cantDias);
	string getclave()const;
	virtual string getTipoVehiculo() = 0;
	void setPrecioBase(float precio);
	string toString(string separador = "\n")const;
	int getCantidadElementosSeguridad();
	void actualizarUltimoMantenimiento();
	float getPrecioCompraVehiculo()const;
};
ostream& operator<<(ostream& out, const cVehiculo* vehiculo);
