#pragma once
#include "cCliente.h"
#include "cVehiculo.h"
#include "cListaElementosSeguridad.h"

class cAlquiler
{
	friend class cListaAlquileres;
	static int cantAlquileres;
	const int codigoReserva;
	cCliente* cliente;
	cVehiculo* vehiculo;
	cListaElementosSeguridad* listaElementosSeguridad;
	cFecha fechaInicioReserva;
	cFecha fechaFinReserva;
	float montoTotal;

public:
	cAlquiler(
		cCliente* cliente = NULL, 
		cVehiculo* vehiculo = NULL, 
		cFecha fechaInicioReserva = cFecha(),
		cFecha fechaFinReserva = cFecha(),
		float montoTotal = 0,
		cListaElementosSeguridad* listaElementosSeguridad = NULL);
	~cAlquiler();
	string getclave()const;
	string toString(string separador= "\n");
	void agregarElementoSeguridad(int elemento, int cantidad);
};
ostream& operator<<(ostream& os, cAlquiler* alquiler);


