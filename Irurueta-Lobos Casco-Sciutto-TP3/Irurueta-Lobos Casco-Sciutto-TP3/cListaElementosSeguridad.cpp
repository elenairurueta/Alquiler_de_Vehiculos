#include "cListaElementosSeguridad.h"

cListaElementosSeguridad::cListaElementosSeguridad(string tipoVehiculo, int cantidadElementos) :cListaT<cElementosSeguridad>(cantidadElementos)
{
	//se construye la lista con los elementos posibles para cada vehiculo
	if ((tipoVehiculo.compare("automovil") == 0) || (tipoVehiculo.compare("trafic") == 0) || (tipoVehiculo.compare("camioneta") == 0))
	{
		cElementosSeguridad* elemento1 = new cElementosSeguridad(SILLA_NINOS, false, 0, PrecioSILLA);
		AgregarItem(elemento1);
	}
	if (tipoVehiculo.compare("motocicleta") == 0)
	{
		cElementosSeguridad* elemento2 = new cElementosSeguridad(CASCO, false, 0, PrecioCASCO);
		AgregarItem(elemento2);
	}
	if (tipoVehiculo.compare("camioneta") == 0)
	{
		cElementosSeguridad* elemento3 = new cElementosSeguridad(PORTAEQUIPAJE, false, 0, PrecioPORTAEQUIPAJE);
		AgregarItem(elemento3);
	}
	if (tipoVehiculo.compare("trafic") == 0)
	{
		cElementosSeguridad* elemento4 = new cElementosSeguridad(ASIENTOS_REVERSIBLES, false, 0, PrecioASIENTO);
		AgregarItem(elemento4);
	}
}
cListaElementosSeguridad::~cListaElementosSeguridad()
{
}

float cListaElementosSeguridad::calcularTarifa(unsigned int dias)
{
	float acum = 0;
	for (unsigned int i = 0; i < CA; i++) //recorremos la lista de elementos
		acum += vector[i]->getPrecioTotal(); //y acumulamos el precio por día de los elementos
	return (acum*dias); //y lo multiplicamos por la cantidad de días
}
