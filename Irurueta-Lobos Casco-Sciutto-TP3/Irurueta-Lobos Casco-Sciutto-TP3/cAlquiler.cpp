#include "cAlquiler.h"
int cAlquiler::cantAlquileres = 0; //inicialización atributo static

#pragma region Constructor y Destructor
cAlquiler::cAlquiler(cFecha* fechaInicioReserva, cFecha* fechaFinReserva, cCliente* cliente, cVehiculo* vehiculo,
	float montoTotal, cListaElementosSeguridad* listaElementosSeguridad):codigoReserva(cantAlquileres++)
{
	if (fechaInicioReserva == NULL)
		fechaInicioReserva = new cFecha(); //si no tiene fecha asignada, la creamos
	cFecha* auxiliar = new cFecha();
	if ((fechaInicioReserva != NULL) && (fechaInicioReserva->compararFechas(auxiliar) == 0))
		fechaInicioReserva->actualizarFecha(); //si la fecha no esta inicializada la actualizamos
	delete auxiliar;
	this->fechaInicioReserva = fechaInicioReserva;
	this->fechaFinReserva = fechaFinReserva;
	this->cliente = cliente;
	this->vehiculo = vehiculo;
	if ((listaElementosSeguridad == NULL) && (vehiculo != NULL)) //y creamos la lista de elementos de seguridad disponibles para agregar
		listaElementosSeguridad = new cListaElementosSeguridad(vehiculo->getTipoVehiculo(), vehiculo->getCantidadElementosSeguridad());
	this->listaElementosSeguridad = listaElementosSeguridad;
	this->montoTotal = montoTotal;
}
cAlquiler::~cAlquiler()
{
	if (!NULL)
		delete fechaInicioReserva;
	if (!NULL)
		delete fechaFinReserva;
	if (!NULL)
		delete listaElementosSeguridad;
}
#pragma endregion

#pragma region toString() e imprimir()
string cAlquiler::toString(string separador)
{
	string cadena = separador + "Codigo de Reserva: " + to_string(codigoReserva);
	if (cliente != NULL)
		cadena += separador + "Cliente: " + cliente->toString(separador + "\t");
	if (vehiculo != NULL)
		cadena += separador + "Vehiculo: " + vehiculo->getTipoVehiculo() + vehiculo->toString(separador + "\t");
	cadena += separador + "Fecha inicio: " + fechaInicioReserva->toString("", false) + separador + "Fecha Fin: ";
	
	cFecha* auxiliar = new cFecha();
	if (fechaFinReserva->compararFechas(auxiliar) == 0)
		cadena += "No definida";
	else
		cadena += fechaFinReserva->toString("", false);
	delete auxiliar;

	if (listaElementosSeguridad != NULL)
		cadena += separador + "Elementos de Seguridad: " + listaElementosSeguridad->toString(separador + "\t");
	cadena += separador + "Monto total: " + to_string(montoTotal);
	return cadena;
}
void cAlquiler::imprimir(string separador)
{
	cout << toString(separador) << endl;
}
#pragma endregion

void cAlquiler::agregarElementoSeguridad(int elemento, int cantidad)
{
	//pasamos el elemento a string para buscarlo en la lista
	string elementoAgregar = "";
	switch (elemento)
	{ 
	case CASCO:
		elementoAgregar = "casco";
		if (cantidad > CASCOSmax) //y acomodamos la cantidad de elementos deseada a lo permitido
			cantidad = CASCOSmax;
		if (cantidad < 0)
			cantidad = 0;
		break;
	case SILLA_NINOS:
		elementoAgregar = "silla ninos";
		if (cantidad > SILLAS_NINOSmax)
			cantidad = SILLAS_NINOSmax;
		if (cantidad < 0)
			cantidad = 0;
		break;
	case PORTAEQUIPAJE:
		elementoAgregar = "portaequipaje";
		if (cantidad > PORTAEQUIPAJESmax)
			cantidad = PORTAEQUIPAJESmax;
		if (cantidad < 0)
			cantidad = 0;
		break;
	case ASIENTOS_REVERSIBLES:
		elementoAgregar = "asientos reversibles";
		if (cantidad > ASIENTOSmax)
			cantidad = ASIENTOSmax;
		if (cantidad < 0)
			cantidad = 0;
		break;
	default:
		elementoAgregar = "";
	}
	if (cantidad == 0)
		return;
	//creamos un puntero que apunte al elemento que se desea agregar
	cElementosSeguridad* ptrElemento = listaElementosSeguridad->BuscarItem(elementoAgregar);
	ptrElemento->setCantidad(cantidad); //cambiamos la cantidad
	ptrElemento->setAgregado(true); //y cambiamos su estado
}
float cAlquiler::actualizarMontoTotal()
{
	float monto = 0;
	unsigned int dias = fechaInicioReserva->calcularDiasDiferencia(fechaFinReserva); //calculamos los dias de alquiler (redondeando para arriba)
	monto += vehiculo->calcularTarifa(dias); //acumulamos la tarifa de los vehiculos
	monto += listaElementosSeguridad->calcularTarifa(dias); //y la de los elementos de seguridad
	this->montoTotal = monto; //y actualizamos el monto
	return montoTotal; //lo devolvemos para luego actualizar las ganancias de la empresa
}

#pragma region Getters
cCliente* cAlquiler::getCliente()
{
	return cliente;
}
int cAlquiler::getElementoSeguridad(int pos)
{
	return (listaElementosSeguridad->getItem(pos))->getTipo();
}
string cAlquiler::getclave()const
{
	return to_string(codigoReserva);
}
#pragma endregion

#pragma region Operators
ostream& operator<<(ostream& os, cAlquiler* alquiler)
{
	if (alquiler == NULL)
		return os;
	os << alquiler->toString();
	return os;
}
#pragma endregion