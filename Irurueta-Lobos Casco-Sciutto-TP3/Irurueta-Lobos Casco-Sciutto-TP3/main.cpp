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
	cAlquiler* alquiler = new cAlquiler();
	cout << alquiler << endl;

	//UNDONE: prueba operador +=
	cListaAlquileres* lista = new cListaAlquileres();
	* lista += alquiler;

	//UNDONE: prueba operador []
	cAlquiler* otroalquiler = new cAlquiler();
	(*lista)[0] = otroalquiler; 

	//UNDONE: prueba tipos vehiculo
	cout << automovil->getTipoVehiculo() << endl;
	cout << automovil->calcularTarifa(2) << endl;
	delete automovil, lista, alquiler, otroalquiler;

	system("pause");
	return 0;
}