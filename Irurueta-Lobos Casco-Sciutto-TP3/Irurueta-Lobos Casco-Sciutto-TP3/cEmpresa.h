#pragma once
#include "cListaT.h"
#include "cVehiculo.h"
#include "cListaAlquileres.h"
#include "cCliente.h"

class cEmpresa
{
	cListaT<cVehiculo>* listaVehiculos;
	cListaAlquileres* listaAlquileres;
	cListaT<cCliente>* listaClientes;

public:
	cEmpresa(cListaT<cVehiculo>* listaVehiculos = NULL, cListaAlquileres* listaAlquileres = NULL, cListaT<cCliente>* listaClientes = NULL);
	~cEmpresa();
	void pasosMantenimiento();
};

