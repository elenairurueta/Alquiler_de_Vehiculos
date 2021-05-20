#include "cElementosSeguridad.h"
cElementosSeguridad::cElementosSeguridad(int tipo, bool agregado, int cantidad, float precio):precio(precio)
{
	this->tipo = tipo;
	this->agregado = agregado;
	this->cantidad = cantidad;
}
cElementosSeguridad::~cElementosSeguridad()
{
}

string cElementosSeguridad::getclave()
{
	switch (tipo)
	{
	case CASCO:
		return "casco";
	case SILLA_NINOS:
		return "silla ninos";
	case PORTAEQUIPAJE:
		return "portaequipaje";
	case ASIENTOS_REVERSIBLES:
		return "asientos reversibles";
	default:
		return "";
	}
}

void cElementosSeguridad::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void cElementosSeguridad::setAgregado(bool agregado)
{
	this->agregado = agregado;
}

string cElementosSeguridad::toString(string separador)
{
	return (separador + "Tipo: " + to_string(tipo) + separador + "Agregado? " + (agregado?("Si" + separador + "Cantidad: " + to_string(cantidad)):"No"));
}

float cElementosSeguridad::getPrecioTotal()
{
	return (precio*cantidad);
}

int cElementosSeguridad::getTipo()
{
	return tipo;
}
