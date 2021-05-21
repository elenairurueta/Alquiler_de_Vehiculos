#include <iostream>
#include <string>
#include "cEmpresa.h"
#include "funciones.h"
using namespace std;

int main() {

	cEmpresa* miEmpresa = new cEmpresa(1000000);
	agregarVehiculos(10, "automovil", miEmpresa);
	agregarVehiculos(10, "camioneta", miEmpresa);
	agregarVehiculos(10, "trafic", miEmpresa);
	agregarVehiculos(10, "motocicleta", miEmpresa);

	nuevosAlquileres(40, miEmpresa);

	retirarVehiculoRandom(miEmpresa);
	mantenimientoVehiculoRandom(miEmpresa);

	////UNDONE: prueba operador <<
	//cAutomovil* automovil = new cAutomovil();
	//cout << automovil << endl;
	//cAlquiler* alquiler = new cAlquiler();
	//cout << alquiler << endl;
	//
	////UNDONE: prueba operador += y +
	//cListaAlquileres* lista = new cListaAlquileres();
	//cAlquiler* otroalquiler = new cAlquiler();
	//(*lista += alquiler) + otroalquiler;

	////UNDONE: prueba operador []
	//(*lista)[0] = otroalquiler; 

	////UNDONE: prueba tipos vehiculo
	//cout << automovil->getTipoVehiculo() << endl;
	//cout << automovil->calcularTarifa(2) << endl;
	//delete automovil, lista, alquiler, otroalquiler;
	delete miEmpresa;

	system("pause");
	return 0;
}