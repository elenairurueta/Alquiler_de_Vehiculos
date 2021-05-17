#include <iostream>
#include <string>
#include "cAutomovil.h"
#include "cListaAlquileres.h"

using namespace std;
//TODO: Sobrecargar el método suma

int main() {


	//UNDONE: prueba operador <<
	cAutomovil* automovil = new cAutomovil();
	cout << automovil << endl;

	//UNDONE: prueba operador +=
	cListaAlquileres* lista = new cListaAlquileres();
	cAlquiler* alquiler = new cAlquiler();
	* lista += alquiler;

	//UNDONE: prueba operador []
	cAlquiler* otroalquiler = new cAlquiler();
	(*lista)[0] = otroalquiler; 

	delete automovil, lista, alquiler, otroalquiler;



	system("pause");
	return 0;
}