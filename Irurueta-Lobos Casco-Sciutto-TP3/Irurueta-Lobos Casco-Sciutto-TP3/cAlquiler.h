#pragma once
#include "cCliente.h"
#include "cVehiculo.h"

class cAlquiler
{
	friend class cListaAlquileres;
	static int cantAlquileres;
	const int codigoReserva;
	cCliente* cliente;
	cVehiculo* vehiculo;
	int cantElementosSeguridad;
	cFecha fechaInicioReserva;
	cFecha fechaFinReserva;
	float montoTotal;

public:
	cAlquiler(
		cCliente* cliente = NULL, 
		cVehiculo* vehiculo = NULL, 
		int cantElementosSeguridad = 0, 
		cFecha fechaInicioReserva = cFecha(), 
		cFecha fechaFinReserva = cFecha(),
		float montoTotal = 0);
	~cAlquiler();
	string getclave()const;
	string toString();
};
ostream& operator<<(ostream& os, cAlquiler* alquiler);


