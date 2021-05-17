#include "cCliente.h"
ostream& operator<<(ostream& os, cCliente* cliente)
{
	os << cliente->toString();
	return os;
}

cCliente::cCliente(string nombre, string DNI, string telefono):nombre(nombre),DNI(DNI),telefono(telefono)
{
}

cCliente::~cCliente()
{
}

string cCliente::getclave()
{
	return DNI;
}

string cCliente::toString()
{
	return ("\n\tDNI: " + DNI + "\n\tNombre: " + nombre + "\n\tTelefono: " + telefono);
}
