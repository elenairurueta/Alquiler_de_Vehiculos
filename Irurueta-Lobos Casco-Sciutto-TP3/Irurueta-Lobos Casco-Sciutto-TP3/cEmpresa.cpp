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

void cEmpresa::pasosMantenimiento(string tipovehiculo)
{
	if (tipovehiculo.compare("automovil")==0)
		cout << "\n\nPasos Mantenimiento AUTOMOVIL" << cAutomovil::getPasosMantenimiento() << endl;	
	else if (tipovehiculo.compare("camioneta") == 0)
		cout << "\n\nPasos Mantenimiento CAMIONETA" << cCamioneta::getPasosMantenimiento() << endl;
	else if (tipovehiculo.compare("motocicleta") == 0)
		cout << "\n\nPasos Mantenimiento MOTOCICLETA" << cMotocicleta::getPasosMantenimiento() << endl;
	else if (tipovehiculo.compare("trafic") == 0)
		cout << "\n\nPasos Mantenimiento TRAFIC" << cTrafic::getPasosMantenimiento() << endl;
}

void cEmpresa::mantenimiento(cVehiculo* vehiculo)
{
	cout << "\n\nVehiculo en mantenimiento: " << vehiculo << endl;
	pasosMantenimiento(vehiculo->getTipoVehiculo());
	vehiculo->actualizarUltimoMantenimiento();
}

void cEmpresa::adquirirVehiculo(cVehiculo* vehiculo)
{
	listaVehiculos->AgregarItem(vehiculo);
}

cVehiculo* cEmpresa::sacarCirculacionVehiculo(cVehiculo* vehiculo)
{
	 return(listaVehiculos->Quitar(vehiculo));
}
