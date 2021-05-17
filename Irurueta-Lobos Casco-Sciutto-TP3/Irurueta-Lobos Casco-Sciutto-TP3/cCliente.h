#pragma once
#include <iostream>
#include <string>
using namespace std;

class cCliente
{
	const string nombre;
	const string DNI;
	const int telefono;

public:


	int getclave();
	string toString();
};
ostream& operator<<(ostream& os, cCliente* cliente);


