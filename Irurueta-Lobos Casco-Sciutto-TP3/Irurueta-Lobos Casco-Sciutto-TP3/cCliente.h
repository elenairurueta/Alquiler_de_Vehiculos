#pragma once
#include <iostream>
#include <string>
using namespace std;

class cCliente
{
public:


	int getclave();
	string toString();
};
ostream& operator<<(ostream& os, cCliente* cliente);


