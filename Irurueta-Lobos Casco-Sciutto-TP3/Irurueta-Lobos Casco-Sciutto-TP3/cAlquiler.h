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
	cFecha* fechaInicioReserva;
	cFecha* fechaFinReserva;
	float montoTotal;

public:
#pragma region Constructor y Destructor
	cAlquiler(cFecha* fechaInicioReserva = NULL,
		cFecha* fechaFinReserva = NULL,
		cCliente* cliente = NULL, 
		cVehiculo* vehiculo = NULL, 
		float montoTotal = 0,
		cListaElementosSeguridad* listaElementosSeguridad = NULL);
	~cAlquiler();
#pragma endregion

#pragma region toString() e imprimir()
	string toString(string separador= "\n");
	void imprimir(string separador = "\n");
#pragma endregion

	//agregamos el elemento de seguridad pasado por parámetro (actualizando la listaElementosSeguridad)
	void agregarElementoSeguridad(int elemento, int cantidad);
	//calculamos el monto total del alquiler sumando el del alquiler del vehiculo según la cantidad de días y el de los elementos de seguridad
	float actualizarMontoTotal();

#pragma region Getters
	string getclave()const;
	cCliente* getCliente();
	int getElementoSeguridad(int pos);
#pragma endregion
};
ostream& operator<<(ostream& os, cAlquiler* alquiler);


