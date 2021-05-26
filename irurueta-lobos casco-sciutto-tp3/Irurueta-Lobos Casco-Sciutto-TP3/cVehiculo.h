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
#pragma region Constructor y Destructor
	cVehiculo(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
		string numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = 0,
		const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = 0, const float precioVehiculo = 0);
	virtual ~cVehiculo();
#pragma endregion
	float calcularTarifa(int cantDias);
	void actualizarUltimoMantenimiento();
#pragma region Getters
	string getclave()const;
	virtual string getTipoVehiculo() = 0;
	int getCantidadElementosSeguridad();
	float getPrecioCompraVehiculo()const;
#pragma endregion
#pragma region Setters
	void setPrecioBase(float precio);
#pragma endregion
#pragma region toString() e imprimir();
	string toString(string separador = "\n")const;
	void imprimir(string separador = "\n");
#pragma endregion
	};
ostream& operator<<(ostream& out, const cVehiculo* vehiculo);
