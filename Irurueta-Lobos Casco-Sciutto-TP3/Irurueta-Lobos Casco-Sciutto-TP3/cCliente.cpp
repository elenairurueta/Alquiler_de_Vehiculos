#include "cCliente.h"
ostream& operator<<(ostream& os, cCliente* cliente)
{
	os << cliente->toString();
	return os;
}

int cCliente::getclave()
{
	return 0;
}

string cCliente::toString()
{
	return string();
}
