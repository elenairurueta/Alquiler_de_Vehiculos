#include "cEmpresa.h"

cEmpresa::cEmpresa(float ganancia, cListaT<cVehiculo>* listaVehiculos, cListaAlquileres* listaAlquileres, cListaT<cCliente>* listaClientes)
{
	this->ganancia = ganancia;
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

void cEmpresa::pasosMantenimiento(cVehiculo* vehiculo)
{
	cAutomovil* ptrAutomovil = dynamic_cast<cAutomovil*>(vehiculo);
	if (ptrAutomovil != NULL)
		cout << "\n\nPasos Mantenimiento AUTOMOVIL" << cAutomovil::getPasosMantenimiento() << endl;	
	cCamioneta* ptrCamioneta = dynamic_cast<cCamioneta*>(vehiculo);
	if (ptrCamioneta != NULL)
		cout << "\n\nPasos Mantenimiento CAMIONETA" << cCamioneta::getPasosMantenimiento() << endl;
	cMotocicleta* ptrMotocicleta = dynamic_cast<cMotocicleta*>(vehiculo);
	if (ptrMotocicleta != NULL)
		cout << "\n\nPasos Mantenimiento MOTOCICLETA" << cMotocicleta::getPasosMantenimiento() << endl;
	cTrafic* ptrTrafic = dynamic_cast<cTrafic*>(vehiculo);
	if (ptrTrafic != NULL)
		cout << "\n\nPasos Mantenimiento TRAFIC" << cTrafic::getPasosMantenimiento() << endl;
}

void cEmpresa::mantenimiento(cVehiculo* vehiculo)
{
	cout << "\n\nVehiculo en mantenimiento: " << vehiculo << endl;
	pasosMantenimiento(vehiculo);
	vehiculo->actualizarUltimoMantenimiento();
}

void cEmpresa::adquirirVehiculo(cVehiculo* vehiculo)
{
	listaVehiculos->AgregarItem(vehiculo);
	ganancia -= vehiculo->getPrecioCompraVehiculo();
}

cVehiculo* cEmpresa::sacarCirculacionVehiculo(string clave)
{
	cVehiculo* vehiculo = listaVehiculos->BuscarItem(clave);
	if (vehiculo == NULL)
		return NULL;
	return(listaVehiculos->Quitar(vehiculo));
}

void cEmpresa::nuevoAlquiler(cAlquiler* alquiler)
{
	cCliente* clienteBuscar = listaClientes->BuscarItem(alquiler->getCliente()->getclave());
	if (clienteBuscar == NULL) {
		(*listaClientes) += (alquiler->getCliente());
	}
	ganancia += alquiler->actualizarMontoTotal();
	listaAlquileres->AgregarItem(alquiler);
}
