#include "cVehiculo.h"
int cVehiculo::precioBase = PRECIO_BASE;
cVehiculo::cVehiculo(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	unsigned int capacidadPasajeros, int cantElementosSeguridad, string elementosSeguridad)
	:numeroPatente(numeroPatente), color(color), numeroChasis(numeroChasis), numeroPoliza(numeroPoliza), capacidadPasajeros(capacidadPasajeros)
{
	this->ultimoMantenimiento = ultimoMantenimiento;
	this->precioAlquilerXDia = precioAlquilerXDia;
	this->cantElementosSeguridad = cantElementosSeguridad;
	this->elementosSeguridad = elementosSeguridad;
}

cVehiculo::~cVehiculo()
{
	if (ultimoMantenimiento != NULL)
		delete ultimoMantenimiento;
}

string cVehiculo::getclave()const
{
	return to_string(numeroPatente);
}

void cVehiculo::setPrecioBase(float precio)
{
	precioBase = precio;
}
string cVehiculo::toString()const
{
	string cadena = "\n\tPatente: " + to_string(numeroPatente) + "\n\tColor: ";
	switch (color) {
	case AMARILLO: cadena += "Amarillo"; break;
	case LILA: cadena += "Lila"; break;
	case DORADO: cadena += "Dorado"; break;
	case FUCSIA: cadena += "Fucsia"; break;
	case VERDE: cadena += "Verde"; break;
	}
	cadena += "\n\tChasis: " + to_string(numeroChasis) + "\n\tPoliza: " + to_string(numeroPoliza) + "\n\tUltimo Mantenimiento: " + ultimoMantenimiento->toString() + "\n\tPrecio Alquiler: " + to_string(precioAlquilerXDia) + "\n\tPrecio Base: " + to_string(precioBase) + "\n\tCapacidad Pasajeros: " + to_string(capacidadPasajeros) + "\n\tCantidad de Elementos de Seguridad: " + to_string(cantElementosSeguridad) + "\n\tElementos de Seguridad: " + elementosSeguridad;
	return cadena;
}


ostream& operator<<(ostream& os, const cVehiculo* vehiculo)
{
	os << vehiculo->toString();
	return os;
}
