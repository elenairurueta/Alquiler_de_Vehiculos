#include <iostream>
#include <string>
#include "cAutomovil.h"
#include "cListaAlquileres.h"

using namespace std;

int main() {

	//UNDONE: prueba operador <<
	cAutomovil* automovil = new cAutomovil();
	cout << automovil << endl;
	cAlquiler* alquiler = new cAlquiler();
	cout << alquiler << endl;

	//UNDONE: prueba operador += y +
	cListaAlquileres* lista = new cListaAlquileres();
	cAlquiler* otroalquiler = new cAlquiler();
	(*lista += alquiler) + otroalquiler;

	//UNDONE: prueba operador []
	(*lista)[0] = otroalquiler; 

	//UNDONE: prueba tipos vehiculo
	cout << automovil->getTipoVehiculo() << endl;
	cout << automovil->calcularTarifa(2) << endl;
	delete automovil, lista, alquiler, otroalquiler;

	system("pause");
	return 0;
}