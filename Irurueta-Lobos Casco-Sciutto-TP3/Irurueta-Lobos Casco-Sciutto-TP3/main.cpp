#include <iostream>
#include <string>
#include "cEmpresa.h"
#include "funciones.h"
using namespace std;

int main() {

	fechaActual->actualizarFecha();
	imprimirFechaActual();

	cEmpresa* miEmpresa = new cEmpresa(1000000);
	agregarVehiculos(20, "automovil", miEmpresa);
	agregarVehiculos(20, "camioneta", miEmpresa);
	agregarVehiculos(20, "trafic", miEmpresa);
	agregarVehiculos(20, "motocicleta", miEmpresa);

	nuevosAlquileres(20, miEmpresa);
	for(int i = 0; i < 20; i++)
		diaSiguiente(miEmpresa);

	system("pause"); system("cls");
	retirarVehiculoRandom(miEmpresa);
	mantenimientoVehiculoRandom(miEmpresa);

	system("pause"); system("cls");
	miEmpresa->getListaAlquileres()->listarPorTipoVehiculo();
	system("pause"); system("cls");

	cout << "Lista de alquileres: " << endl;
	miEmpresa->getListaAlquileres()->Listar("\n\n");
	system("pause"); system("cls");

	cout << "prueba sobrecarga [] y <<" << endl;
	cout << (*(miEmpresa->getListaAlquileres()))[0] << endl;
	system("pause"); system("cls");

	delete miEmpresa;
	delete fechaActual;
	system("pause");
	return 0;
}