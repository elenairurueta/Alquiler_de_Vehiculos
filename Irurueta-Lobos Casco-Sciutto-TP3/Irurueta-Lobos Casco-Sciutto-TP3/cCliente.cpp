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

int cCliente::getclave()
{
	return 0;
}

string cCliente::toString()
{
	return string();
}
