#include "cVehiculo.h"

int cVehiculo::precioBase = PRECIO_BASE;
cVehiculo::cVehiculo(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
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

float cVehiculo::calcularTarifa(int cantDias)
{
	return (precioAlquilerXDia * cantDias + precioBase);
}

string cVehiculo::getclave()const
{
	return to_string(numeroPatente);
}

void cVehiculo::setPrecioBase(float precio)
{
	precioBase = precio;
}
string cVehiculo::toString(string separador)const
{
	string cadena = separador + "Patente: " + to_string(numeroPatente) + separador + "Color: ";
	switch (color) {
	case AMARILLO: cadena += "Amarillo"; break;
	case LILA: cadena += "Lila"; break;
	case DORADO: cadena += "Dorado"; break;
	case FUCSIA: cadena += "Fucsia"; break;
	case VERDE: cadena += "Verde"; break;
	}
	cadena += separador + "Chasis: " + to_string(numeroChasis) + separador + "Poliza: " + to_string(numeroPoliza) + separador + "Ultimo Mantenimiento: " + ultimoMantenimiento->toString() + separador + "Precio Alquiler: " + to_string(precioAlquilerXDia) + "\n\tPrecio Base: " + to_string(precioBase) + "\n\tCapacidad Pasajeros: " + to_string(capacidadPasajeros);
	return cadena;
}

int cVehiculo::getCantidadElementosSeguridad()
{
	return cantElementosSeguridad;
}

void cVehiculo::actualizarUltimoMantenimiento()
{
	ultimoMantenimiento->actualizarFecha();
}

float cVehiculo::getPrecioCompraVehiculo() const
{
	return precioVehiculo;
}


ostream& operator<<(ostream& os, const cVehiculo* vehiculo)
{
	os << vehiculo->toString();
	return os;
}
