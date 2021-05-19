#include "funciones.h"

int cantVehiculosAgregados = 0;

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
		miEmpresa->adquirirVehiculo(miVehiculo);
	}
}
void retirarVehiculoRandom(cEmpresa* miEmpresa) {
	cVehiculo* vehiculoQuitado = miEmpresa->sacarCirculacionVehiculo(PATENTES[rand() % cantVehiculosAgregados]);
	cout << "Se saco de circulacion el vehiculo: " << vehiculoQuitado << endl;
}