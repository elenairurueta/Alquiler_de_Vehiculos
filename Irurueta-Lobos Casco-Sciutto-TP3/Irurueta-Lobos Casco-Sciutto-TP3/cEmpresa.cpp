#include "cEmpresa.h"

#pragma region Constructor y Destructor
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
#pragma endregion

void cEmpresa::pasosMantenimiento(cVehiculo* vehiculo)
{
	//hacemos dynamic cast para idenificar que vehículo es el pasado por parámetro
	cAutomovil* ptrAutomovil = dynamic_cast<cAutomovil*>(vehiculo);
	if (ptrAutomovil != NULL)
		cout << "\n\nPasos Mantenimiento AUTOMOVIL" << cAutomovil::getPasosMantenimiento() << endl; //e imprimimos los pasos mantenimiento que correspondan
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
	if(vehiculo == NULL)
		return;
	//TODO: verificar que no este alquilado
	if(listaAlquileres->chequearVehiculoEnAlquiler(vehiculo) == true){
		cout << "\n\nNo se puede realizar el mantenimiento del vehiculo " << vehiculo->getclave() << " porque se encuentra alquilado." << endl;
		return;
	}
	cout << "\n\nVehiculo en mantenimiento: " << vehiculo << endl;
	pasosMantenimiento(vehiculo);
	vehiculo->actualizarUltimoMantenimiento();
}
void cEmpresa::adquirirVehiculo(cVehiculo* vehiculo)
{
	if(vehiculo == NULL)
		return;
	listaVehiculos->AgregarItem(vehiculo);
	ganancia -= vehiculo->getPrecioCompraVehiculo();
}
cVehiculo* cEmpresa::sacarCirculacionVehiculo(string clave)
{
	cVehiculo* vehiculo = listaVehiculos->BuscarItem(clave);
	if (vehiculo == NULL)
		return NULL;
	if (listaAlquileres->chequearVehiculoEnAlquiler(vehiculo))
		return NULL;
	return(listaVehiculos->Quitar(vehiculo));
}
void cEmpresa::nuevoAlquiler(cAlquiler* alquiler)
{
	if(alquiler == NULL)
		return;
	cCliente* clienteBuscar = listaClientes->BuscarItem(alquiler->getCliente()->getclave());
	if (clienteBuscar == NULL) {
		(*listaClientes) += (alquiler->getCliente());
	}
	ganancia += alquiler->actualizarMontoTotal();
	if (!listaAlquileres->AgregarItem(alquiler))
		throw new exception("El alquiler que se está intentado agregar ya se encuentra en la lista");
}
void cEmpresa::terminarAlquileres(cFecha* fechaActual)
{
	if(fechaActual == NULL)
		return;
	listaAlquileres->quitarPorFecha(fechaActual);
}

#pragma region Getters
cVehiculo* cEmpresa::getVehiculoCategoria(string categoria)
{
	for (int i = 0; i < listaVehiculos->getCA(); i++) {

		if (categoria == "automovil") {
			cAutomovil* ptrAutomovil = dynamic_cast<cAutomovil*>((*listaVehiculos)[i]);
			if (ptrAutomovil != NULL) {
				if(!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i]))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "camioneta") {
			cCamioneta* ptrCamioneta = dynamic_cast<cCamioneta*>((*listaVehiculos)[i]);
			if (ptrCamioneta != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i]))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "motocicleta") {
			cMotocicleta* ptrMotocicleta = dynamic_cast<cMotocicleta*>((*listaVehiculos)[i]);
			if (ptrMotocicleta != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i]))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "trafic") {
			cTrafic* ptrTrafic = dynamic_cast<cTrafic*>((*listaVehiculos)[i]);
			if (ptrTrafic != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i]))
					return (*listaVehiculos)[i];
			}
		}
	}
	return NULL;
}
cVehiculo* cEmpresa::getVehiculo(string clave)
{
	return listaVehiculos->BuscarItem(clave);
}
cListaAlquileres* cEmpresa::getListaAlquileres()
{
	return listaAlquileres;
}
#pragma endregion

#pragma region toString() e imprimir()
string cEmpresa::toString(string separador){
	return(separador + "Ganancia: " + ganancia + separador + "Lista Clientes: " + listaClientes->toString() + separador + "Lista Vehiculos: " + listaVehiculos->toString() + separador + "Lista Alquileres: " + listaAlquileres->toString());
}
void cEmpresa::imprimir(string separador){
	cout << toString(separador) << endl;
}
#pragma endregion
