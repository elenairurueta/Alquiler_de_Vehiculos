#include "cCliente.h"
ostream& operator<<(ostream& os, cCliente* cliente)
{
	os << cliente->toString("\n");
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

string cCliente::toString(string separador)
{
	return (separador + "DNI: " + DNI + separador + "Nombre: " + nombre + separador + "Telefono: " + telefono);
}
