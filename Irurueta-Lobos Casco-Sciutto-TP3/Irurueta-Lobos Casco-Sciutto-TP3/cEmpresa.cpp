#include "cEmpresa.h"

cEmpresa::cEmpresa(cListaT<cVehiculo>* listaVehiculos, cListaAlquileres* listaAlquileres, cListaT<cCliente>* listaClientes)
{
	if (listaVehiculos == NULL)
		listaVehiculos = new cListaT<cVehiculo>();
	this->listaVehiculos = listaVehiculos;
	if (listaAlquileres == NULL)
		listaAlquileres = new cListaAlquileres();
	this->listaAlquileres = listaAlquileres;
	if (listaClientes == NULL)
		listaClientes = new cListaT<cCliente>();
	this->listaClientes = listaClientes;
}

cEmpresa::~cEmpresa()
{
	if (listaVehiculos != NULL)
		delete listaVehiculos;
	if (listaAlquileres != NULL)
		delete listaAlquileres;
	if (listaClientes != NULL)
		delete listaClientes;
}

void cEmpresa::pasosMantenimiento()
{
	listaVehiculos->
}
