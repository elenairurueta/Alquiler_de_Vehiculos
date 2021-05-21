#pragma once
#include <iostream>
#include <string>
using namespace std;

class cCliente
{
	const string nombre;
	const string DNI;
	const string telefono;

public:
#pragma region Constructor y Destructor
	cCliente(string nombre="", string DNI="", string telefono="");
	~cCliente();
#pragma endregion

#pragma region toString() e imprimir()
	string toString(string separador);
	void imprimir(string separador);
#pragma endregion

#pragma region Getters
	string getclave();
#pragma endregion

};
ostream& operator<<(ostream& os, cCliente* cliente);


