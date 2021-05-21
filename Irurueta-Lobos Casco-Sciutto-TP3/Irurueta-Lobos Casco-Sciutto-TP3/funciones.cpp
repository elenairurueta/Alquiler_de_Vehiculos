#include "funciones.h"

int cantVehiculosAgregados = 0;
int cantClientesAgregados = 0;
cFecha* fechaActual = new cFecha();

void agregarVehiculos(int cantidad, string tipo, cEmpresa* miEmpresa)
{
	cVehiculo* miVehiculo = NULL;
	srand(time(NULL));
	cFecha fechaMantenimiento;
	for (int i = 0; i < cantidad; i++) {
		fechaMantenimiento.actualizarFecha();
		if (tipo.compare("automovil") == 0)
			miVehiculo = new cAutomovil(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("camioneta") == 0)
			miVehiculo = new cCamioneta(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("trafic") == 0)
			miVehiculo = new cTrafic(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("motocicleta") == 0)
			miVehiculo = new cMotocicleta(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		cantVehiculosAgregados++;
		try {
			miEmpresa->adquirirVehiculo(miVehiculo);
		}
		catch (exception* ex) {
			cout << ex->what() << endl; delete ex;
		}
	}
}
void retirarVehiculoRandom(cEmpresa* miEmpresa) {
	cVehiculo* vehiculoQuitado = miEmpresa->sacarCirculacionVehiculo(PATENTES[rand() % cantVehiculosAgregados]);
	if(vehiculoQuitado == NULL)
		cout << "El vehiculo no puede ser sacado de circulacion porque se encuentra alquilado" << endl;
	else 
		cout << "Se saco de circulacion el vehiculo" << endl;
}
void nuevosAlquileres(int cantidad, cEmpresa* miEmpresa) {
	cAlquiler* miAlquiler = NULL; cCliente* miCliente = NULL; cVehiculo* miVehiculo = NULL;
	for (int i = 0; i < cantidad; i++)
	{
		srand(time(NULL));
		miCliente = new cCliente(NOMBRES[cantClientesAgregados], DNIS[cantClientesAgregados], TELEFONOS[cantClientesAgregados]);
		
		miVehiculo = miEmpresa->getVehiculoCategoria(CATEGORIAS[rand() % cantCATEGORIAS]);
		if (miVehiculo == NULL) {
			cout << "No hay vehiculos disponibles de la categoria solicitada" << endl;
			continue;
		}
		cFecha* fechaInicio = new cFecha(), *fechaFin = new cFecha();
		getFechasRandomNuevoAlquiler(fechaInicio, fechaFin);
		miAlquiler = new cAlquiler(fechaInicio, fechaFin, miCliente, miVehiculo);
		agregarElementosSeguridad(miAlquiler, miVehiculo);
		try {
			miEmpresa->nuevoAlquiler(miAlquiler);
		}
		catch (exception* ex) {
			cout << ex->what() << endl; delete ex;
		}
		cantClientesAgregados++;
	}

}
void getFechasRandomNuevoAlquiler(cFecha* fechaInicio, cFecha* fechaFin) {
	if ((fechaInicio == NULL) || (fechaFin == NULL))
		return;
	fechaInicio->actualizarFecha(); fechaFin->actualizarFecha();
	srand(time(NULL));
	short randomDiasInicio = rand() % 5 + 1; short randomMesesInicio = 0;//rand() % 2;
	short randomDiasDiferencia = rand() % 10 + 1; short randomMesesDiferencia = 0;// rand() % 2;
	fechaInicio->incrementarFecha(randomDiasInicio, randomMesesInicio);
	fechaFin->incrementarFecha(randomDiasInicio + randomDiasDiferencia, randomMesesInicio + randomMesesDiferencia);
}
void agregarElementosSeguridad(cAlquiler* miAlquiler, cVehiculo* miVehiculo) {
	for (int i = 0; i < miVehiculo->getCantidadElementosSeguridad(); i++) {
		int elementoSeguridad = miAlquiler->getElementoSeguridad(i);
		int cantidadESagregar = rand() % 3; //si es más o menos de lo permitido, se arregla en agregarElementoSeguridad()
		miAlquiler->agregarElementoSeguridad(elementoSeguridad, cantidadESagregar);
	}
}
void mantenimientoVehiculoRandom(cEmpresa* miEmpresa) {
	miEmpresa->mantenimiento(miEmpresa->getVehiculo(PATENTES[rand() % cantVehiculosAgregados]));
}
void imprimirFechaActual() {
	system("cls");
	cout << "\n\n\t\t\t[ " << fechaActual << " ]\n\n";
}
void diaSiguiente(cEmpresa* miEmpresa)
{
	fechaActual->incrementarFecha(1);
	try {
		miEmpresa->terminarAlquileres(fechaActual);
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
	}
	imprimirFechaActual();
}
