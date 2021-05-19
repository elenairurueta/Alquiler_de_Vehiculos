#include "cVehiculo.h"

int cVehiculo::precioBase = PRECIO_BASE;
cVehiculo::cVehiculo(unsigned int numeroPatente, unsigned int color, unsigned int numeroChasis,
	unsigned int numeroPoliza, cFecha* ultimoMantenimiento, float precioAlquilerXDia,
	unsigned int capacidadPasajeros, int cantElementosSeguridad, const string pasosMantenimiento)
	:numeroPatente(numeroPatente), color(color), numeroChasis(numeroChasis), numeroPoliza(numeroPoliza), capacidadPasajeros(capacidadPasajeros), cantElementosSeguridad(cantElementosSeguridad), pasosMantenimiento(pasosMantenimiento)
{
	this->ultimoMantenimiento = ultimoMantenimiento;
	this->precioAlquilerXDia = precioAlquilerXDia;
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
	cadena += separador + "Chasis: " + to_string(numeroChasis) + separador + "Poliza: " + to_string(numeroPoliza) + separador + "Ultimo Mantenimiento: " + ultimoMantenimiento->toString() + separador + "Precio Alquiler: " + to_string(precioAlquilerXDia) + "\n\tPrecio Base: " + to_string(precioBase) + "\n\tCapacidad Pasajeros: " + to_string(capacidadPasajeros) + separador + "Cantidad de Elementos de Seguridad: " + to_string(cantElementosSeguridad) + separador + "Elementos de Seguridad: " + elementosSeguridad;
	return cadena;
}


ostream& operator<<(ostream& os, const cVehiculo* vehiculo)
{
	os << vehiculo->toString();
	return os;
}
