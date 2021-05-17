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
	cCliente(string nombre="", string DNI="", string telefono="");
	~cCliente();
	string getclave();
	string toString();
};
ostream& operator<<(ostream& os, cCliente* cliente);


