#include <iostream>
#include <string>
#include "cListaAlquileres.h"
using namespace std;

int main() {

	cListaAlquileres *aux = new cListaAlquileres();
	cAlquiler aux2 = aux[0];

	system("pause");

	delete aux;
	return 0;
}