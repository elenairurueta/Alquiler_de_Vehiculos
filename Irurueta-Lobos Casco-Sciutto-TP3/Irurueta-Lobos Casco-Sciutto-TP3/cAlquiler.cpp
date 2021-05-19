#include "cAlquiler.h"
int cAlquiler::cantAlquileres = 0;
cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, cFecha fechaInicioReserva, 
	cFecha fechaFinReserva, float montoTotal, cListaElementosSeguridad* listaElementosSeguridad):codigoReserva(cantAlquileres++)
{
	cFecha *auxiliar = new cFecha();
	if (fechaInicioReserva.compararFechas(auxiliar) == 0)
		fechaInicioReserva.actualizarFecha();
	delete auxiliar;
	this->fechaInicioReserva = fechaInicioReserva;
	this->cliente = cliente;
	this->vehiculo = vehiculo;
	if ((listaElementosSeguridad == NULL) && (vehiculo != NULL))
		listaElementosSeguridad = new cListaElementosSeguridad(vehiculo->getTipoVehiculo(), vehiculo->getCantidadElementosSeguridad());
	this->listaElementosSeguridad = listaElementosSeguridad;
	this->fechaInicioReserva = fechaInicioReserva;
	this->fechaFinReserva = fechaFinReserva;
	this->montoTotal = montoTotal;
}

cAlquiler::~cAlquiler()
{
}

string cAlquiler::getclave()const
{
	return to_string(codigoReserva);
}

string cAlquiler::toString(string separador)
{
	string cadena = separador + "Codigo de Reserva: " + to_string(codigoReserva);
	if (cliente != NULL)
		cadena += separador + "Cliente: " + cliente->toString("\n");
	if (vehiculo != NULL)
		cadena += separador + "Vehiculo: " + vehiculo->getTipoVehiculo() + vehiculo->toString();
	cadena += separador + "Fecha inicio: " + fechaInicioReserva.toString() + separador + "Fecha Fin: ";
	
	cFecha* auxiliar = new cFecha();
	if (fechaFinReserva.compararFechas(auxiliar) == 0)
		cadena += "No definida";
	else
		cadena += fechaFinReserva.toString();
	delete auxiliar;

	if (listaElementosSeguridad != NULL)
		cadena += separador + "Elementos de Seguridad: " + listaElementosSeguridad->toString();
	cadena += separador + "Monto total: " + to_string(montoTotal);
	return cadena;
}
void cAlquiler::agregarElementoSeguridad(int elemento, int cantidad)
{
	string elementoAgregar = "";
	switch (elemento)
	{ 
	case CASCO:
		elementoAgregar = "casco";
		if (cantidad > CASCOSmax)
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
	cElementosSeguridad* ptrElemento = listaElementosSeguridad->BuscarItem(elementoAgregar);
	ptrElemento->setCantidad(cantidad);
	ptrElemento->setAgregado(true);
}
float cAlquiler::calcularMontoTotal()
{
	float monto = 0;
	unsigned int dias = fechaInicioReserva.calcularDiasDiferencia(&fechaFinReserva);
	monto += vehiculo->calcularTarifa(dias);
	monto += listaElementosSeguridad->calcularTarifa(dias);
	return monto;
}
ostream& operator<<(ostream& os, cAlquiler* alquiler)
{
	if (alquiler == NULL)
		return os;
	os << alquiler->toString();
	return os;
}
