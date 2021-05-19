#pragma once
#include "cListaT.h"
#include "cAutomovil.h"
#include "cCamioneta.h"
#include "cTrafic.h"
#include "cMotocicleta.h"
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
	void pasosMantenimiento(string tipovehiculo);
	void mantenimiento(cVehiculo* vehiculo);
	void adquirirVehiculo(cVehiculo* vehiculo);
	cVehiculo* sacarCirculacionVehiculo(cVehiculo* vehiculo);
};

