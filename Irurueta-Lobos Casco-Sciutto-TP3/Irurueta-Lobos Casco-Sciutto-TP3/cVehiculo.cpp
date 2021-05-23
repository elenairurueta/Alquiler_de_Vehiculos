#include "cVehiculo.h"

int cVehiculo::precioBase = PRECIO_BASE;

#pragma region Constructor y Destructor
cVehiculo::cVehiculo(string numeroPatente, unsigned int color, string numeroChasis,
	string numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	unsigned int capacidadPasajeros, int cantElementosSeguridad, const float precioVehiculo)
	:numeroPatente(numeroPatente), color(color), numeroChasis(numeroChasis), 
	numeroPoliza(numeroPoliza), capacidadPasajeros(capacidadPasajeros), 
	cantElementosSeguridad(cantElementosSeguridad), precioVehiculo(precioVehiculo)
{
	this->ultimoMantenimiento = ultimoMantenimiento;
	this->precioAlquilerXDia = precioAlquilerXDia;
}

cVehiculo::~cVehiculo()
{
	if (ultimoMantenimiento != NULL)
		delete ultimoMantenimiento;
}
#pragma endregion

float cVehiculo::calcularTarifa(int cantDias)
{
	return (precioAlquilerXDia * cantDias + precioBase); //calculamos la tarifa del vehiculo por la cantidad de dias pasada por parámetro
}
void cVehiculo::actualizarUltimoMantenimiento()
{
	ultimoMantenimiento->actualizarFecha(); //actualizamos la fecha de ultimo mantenimiento del vehiculo a la actual
}

#pragma region Getters
string cVehiculo::getclave()const
{
	return numeroPatente;
}
float cVehiculo::getPrecioCompraVehiculo() const
{
	return precioVehiculo;
}
int cVehiculo::getCantidadElementosSeguridad()
{
	return cantElementosSeguridad;
}
#pragma endregion

#pragma region Setters
void cVehiculo::setPrecioBase(float precio)
{
	precioBase = precio;
}
#pragma endregion

#pragma region toString() e imprimir()
string cVehiculo::toString(string separador)const
{
	string cadena = separador + "Patente: " + numeroPatente + separador + "Color: ";
	switch (color) {
	case AMARILLO: cadena += "Amarillo"; break;
	case LILA: cadena += "Lila"; break;
	case DORADO: cadena += "Dorado"; break;
	case FUCSIA: cadena += "Fucsia"; break;
	case VERDE: cadena += "Verde"; break;
	}
	cadena += separador + "Chasis: " + numeroChasis + separador + "Poliza: " + numeroPoliza + separador + "Ultimo Mantenimiento: " + ultimoMantenimiento->toString() + separador + "Precio Alquiler: " + to_string(precioAlquilerXDia) + separador + "Precio Base: " + to_string(precioBase) + separador + "Capacidad Pasajeros: " + to_string(capacidadPasajeros);
	return cadena;
}
void cVehiculo::imprimir(string separador)
{
	cout << toString(separador) << endl;
}
#pragma endregion

#pragma region Operators
ostream& operator<<(ostream& os, const cVehiculo* vehiculo)
{
	os << vehiculo->toString();
	return os;
}
#pragma endregion
