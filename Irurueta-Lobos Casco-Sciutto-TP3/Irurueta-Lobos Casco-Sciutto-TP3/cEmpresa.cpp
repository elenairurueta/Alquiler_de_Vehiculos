#include "cEmpresa.h"

#pragma region Constructor y Destructor
cEmpresa::cEmpresa(float ganancia, cListaT<cVehiculo>* listaVehiculos, cListaAlquileres* listaAlquileres, cListaT<cCliente>* listaClientes)
{
	this->ganancia = ganancia;
	if (listaVehiculos == NULL)
		listaVehiculos = new cListaT<cVehiculo>();//creamos una lista de vehiculos utilizando la template
	this->listaVehiculos = listaVehiculos;
	if (listaAlquileres == NULL)
		listaAlquileres = new cListaAlquileres();//creamos una lista de alquileres utilizando la template
	this->listaAlquileres = listaAlquileres;
	if (listaClientes == NULL)
		listaClientes = new cListaT<cCliente>();//creamos una lista de clientes utilizando la template
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
	//hacemos dynamic cast para identificar que vehículo es el pasado por parámetro e imprimimos los pasos mantenimiento que correspondan
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
	if(vehiculo == NULL)
		return;

	if(listaAlquileres->chequearVehiculoEnAlquiler(vehiculo) == true){ //nos fijamos que el vehículo no este alquilado
		cout << "\n\nNo se puede realizar el mantenimiento del vehiculo " << vehiculo->getclave() << " porque se encuentra alquilado." << endl;
		return;
	}
	cout << "\n\nVehiculo en mantenimiento: " << vehiculo << endl;
	pasosMantenimiento(vehiculo);//imprimimos los pasos de su mantenimiento
	vehiculo->actualizarUltimoMantenimiento();//actualizamos la fecha de su último mantenimiento
}
void cEmpresa::adquirirVehiculo(cVehiculo* vehiculo)//pasamos por parámetro el vehículo a adquirir por la empresa
{
	if(vehiculo == NULL)
		return;
	listaVehiculos->AgregarItem(vehiculo);//agregamos el vehículo a la lista de vehículos
	ganancia -= vehiculo->getPrecioCompraVehiculo();//le restamos a la ganancia el precio del vehículo
}
cVehiculo* cEmpresa::sacarCirculacionVehiculo(string clave)
{
	//buscamos por patente al vehículo en la lista y lo igualamos a un puntero de cVehiculo
	cVehiculo* vehiculo = listaVehiculos->BuscarItem(clave);
	if (vehiculo == NULL)//si no lo encuentra devuelve NULL
		return NULL;
	if (listaAlquileres->chequearVehiculoEnAlquiler(vehiculo))//si lo encuentra y está en alquiler también devuelve NULL
		return NULL;
	cVehiculo* vehiculoQuitado = listaVehiculos->Quitar(vehiculo);//saca al vehículo de la lista
	return vehiculoQuitado;
}
void cEmpresa::nuevoAlquiler(cAlquiler* alquiler)
{
	if(alquiler == NULL)
		return;
	//buscamos por DNI al cliente en la lista y lo igualamos a un puntero de cCliente
	cCliente* clienteBuscar = listaClientes->BuscarItem(alquiler->getCliente()->getclave());
	if (clienteBuscar == NULL) {//si no lo encuentra, agrega al cliente en la lista de clientes
		(*listaClientes) += (alquiler->getCliente());
	}
	ganancia += alquiler->actualizarMontoTotal();//sumamos el monto del nuevo alquiler a la ganancia
	bool sePudoAgregar = listaAlquileres->AgregarItem(alquiler);//lo agregamos a la lista de alquileres
	if (!sePudoAgregar)//si no se pudo agregar arroja una excepción
		throw new exception("El alquiler que se está intentado agregar ya se encuentra en la lista");
}
cListaAlquileres* cEmpresa::terminarAlquileres(cFecha* fechaActual)//si concluyó su alquiler, lo quitamos de la lista
{
	if(fechaActual == NULL)
		return NULL;
	return (listaAlquileres->quitarPorFecha(fechaActual));
}

#pragma region Getters
cVehiculo* cEmpresa::getVehiculoCategoria(string categoria, cFecha* fechaInicio, cFecha* fechaFin)
{
	if (fechaInicio == NULL || fechaFin == NULL)
		return NULL;
	//utilizamos dynamic_cast para fijarnos a que clase hija pertenece, devuelve NULL si no corresponde
	for (int i = 0; i < listaVehiculos->getCA(); i++) {

		if (categoria == "automovil") {
			cAutomovil* ptrAutomovil = dynamic_cast<cAutomovil*>((*listaVehiculos)[i]);
			if (ptrAutomovil != NULL) {
				if(!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i], fechaInicio, fechaFin))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "camioneta") {
			cCamioneta* ptrCamioneta = dynamic_cast<cCamioneta*>((*listaVehiculos)[i]);
			if (ptrCamioneta != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i], fechaInicio, fechaFin))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "motocicleta") {
			cMotocicleta* ptrMotocicleta = dynamic_cast<cMotocicleta*>((*listaVehiculos)[i]);
			if (ptrMotocicleta != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i], fechaInicio, fechaFin))
					return (*listaVehiculos)[i];
			}
		}
		else if (categoria == "trafic") {
			cTrafic* ptrTrafic = dynamic_cast<cTrafic*>((*listaVehiculos)[i]);
			if (ptrTrafic != NULL) {
				if (!listaAlquileres->chequearVehiculoEnAlquiler((*listaVehiculos)[i], fechaInicio, fechaFin))
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
cListaT<cVehiculo>* cEmpresa::getListaVehiculos()
{
	return listaVehiculos;
}
#pragma endregion

#pragma region toString() e imprimir()
string cEmpresa::toString(string separador){
	return(separador + "Ganancia: " + to_string(ganancia) + separador + "Lista Clientes: " + listaClientes->toString() + separador + "Lista Vehiculos: " + listaVehiculos->toString() + separador + "Lista Alquileres: " + listaAlquileres->toString());
}
void cEmpresa::imprimir(string separador){
	cout << toString(separador) << endl;
}
#pragma endregion
