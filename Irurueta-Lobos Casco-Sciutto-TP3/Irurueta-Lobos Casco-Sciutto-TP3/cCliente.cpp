#include "cCliente.h"

#pragma region Constructor y Destructor
cCliente::cCliente(string nombre, string DNI, string telefono):nombre(nombre),DNI(DNI),telefono(telefono)
{
}
cCliente::~cCliente()
{
}
#pragma endregion

#pragma region Getters
string cCliente::getclave()
{
	return DNI;
}
#pragma endregion

#pragma region toString() e imprimir()
string cCliente::toString(string separador)
{
	return (separador + "DNI: " + DNI + separador + "Nombre: " + nombre + separador + "Telefono: " + telefono);
}
void cCliente::imprimir(string separador)
{
	cout << toString(separador) << endl;
}
#pragma endregion

#pragma region Operators
ostream& operator<<(ostream& os, cCliente* cliente)
{
	os << cliente->toString("\n");
	return os;
}
#pragma endregion
