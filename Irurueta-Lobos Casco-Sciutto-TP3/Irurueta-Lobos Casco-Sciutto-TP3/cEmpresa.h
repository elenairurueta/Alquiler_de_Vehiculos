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
	float ganancia;

public:
	cEmpresa(float ganancia = 0, cListaT<cVehiculo>* listaVehiculos = NULL, cListaAlquileres* listaAlquileres = NULL, cListaT<cCliente>* listaClientes = NULL);
	~cEmpresa();
	void pasosMantenimiento(cVehiculo* vehiculo);
	void mantenimiento(cVehiculo* vehiculo);
	void adquirirVehiculo(cVehiculo* vehiculo);
	cVehiculo* sacarCirculacionVehiculo(string clave);
	void nuevoAlquiler(cAlquiler* alquiler);
	cVehiculo* getVehiculoCategoria(string categoria);
	cVehiculo* getVehiculo(string clave);
	void terminarAlquileres(cFecha* fechaActual);
};

