#include "cElementosSeguridad.h"

#pragma region Constructor y Destructor
cElementosSeguridad::cElementosSeguridad(int tipo, bool agregado, int cantidad, float precio):precio(precio)
{
	this->tipo = tipo;
	this->agregado = agregado;
	this->cantidad = cantidad;
}
cElementosSeguridad::~cElementosSeguridad()
{
}
#pragma endregion

#pragma region Getters
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
float cElementosSeguridad::getPrecioTotal()
{
	return (precio*cantidad); //precio total de un elemento de seguridad
}

int cElementosSeguridad::getTipo()
{
	return tipo;
}

#pragma endregion

#pragma region Setters
void cElementosSeguridad::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}
void cElementosSeguridad::setAgregado(bool agregado)
{
	this->agregado = agregado;
}
#pragma endregion

#pragma region toString() e imprimir()
string cElementosSeguridad::toString(string separador)
{
	return (separador + "Tipo: " + to_string(tipo) + separador + "Agregado? " + (agregado?("Si" + separador + "Cantidad: " + to_string(cantidad)):"No"));
}
void cElementosSeguridad::imprimir(string separador)
{
	cout << toString(separador) << endl;
}
#pragma endregion
