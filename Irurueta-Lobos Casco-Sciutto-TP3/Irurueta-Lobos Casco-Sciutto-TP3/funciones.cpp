#include "funciones.h"

int cantVehiculosAgregados = 0;
int cantClientesAgregados = 0;
cFecha* fechaActual = new cFecha();

void agregarVehiculos(int cantidad, string tipo, cEmpresa* miEmpresa)
{
	cVehiculo* miVehiculo = NULL;
	srand(time(NULL));
	cFecha fechaMantenimiento;
	//Recorro la cantidad de los vehiculos a agregar y verifico que categoria de vehiculo es
	for (int i = 0; i < cantidad; i++) {
		fechaMantenimiento.actualizarFecha(); //La ultima fecha de mantenimiento se determina como la fecha de adquisicion del mismo
		if (tipo.compare("automovil") == 0)
			miVehiculo = new cAutomovil(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("camioneta") == 0)
			miVehiculo = new cCamioneta(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("trafic") == 0)
			miVehiculo = new cTrafic(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		else if (tipo.compare("motocicleta") == 0)
			miVehiculo = new cMotocicleta(PATENTES[cantVehiculosAgregados], (rand() % 5), NUMEROSDECHASIS[cantVehiculosAgregados], NUMEROPOLIZA[cantVehiculosAgregados]);
		cantVehiculosAgregados++; //Aumento la variable global de vehiculos agregados
		try {
			miEmpresa->adquirirVehiculo(miVehiculo); // Se agrega a la empresa el vehiculo 
		}
		catch (exception* ex) {
			cout << ex->what() << endl; delete ex;
		}
	}
}
void retirarVehiculoRandom(cEmpresa* miEmpresa) {
	//Le paso una patente de la lista de patentes creada en "datosVehiculo.h" para sacar de circulacion
	cVehiculo* vehiculoQuitado = miEmpresa->sacarCirculacionVehiculo(PATENTES[rand() % cantVehiculosAgregados]);
	//Si no la encuentra o esta en alquiler, devuelve NULL
	if(vehiculoQuitado == NULL)
		cout << "El vehiculo no puede ser sacado de circulacion porque se encuentra alquilado" << endl;
	else 
		cout << "Se saco de circulacion el vehiculo: " << vehiculoQuitado << endl;
	delete vehiculoQuitado;
}
void nuevosAlquileres(int cantidad, cEmpresa* miEmpresa) {
	cAlquiler* miAlquiler = NULL; cCliente* miCliente = NULL; cVehiculo* miVehiculo = NULL;
	srand(time(NULL));
	//Recorro la cantidad de alquileres a agregar 
	for (int i = 0; i < cantidad; i++)
	{   //Creo un cliente de la los datos de clientes en "datosClientes.h"
		miCliente = new cCliente(NOMBRES[cantClientesAgregados], DNIS[cantClientesAgregados], TELEFONOS[cantClientesAgregados]);
		//Determino la fecha de inicio, fin y duracion del alquiler
		cFecha* fechaInicio = new cFecha(), * fechaFin = new cFecha();
		getFechasRandomNuevoAlquiler(fechaInicio, fechaFin);
		//Busco un vehiculo de la categoria deseada
		miVehiculo = miEmpresa->getVehiculoCategoria((CATEGORIAS[rand() % cantCATEGORIAS]), fechaInicio, fechaFin);
		//Si no encuentra un vehiculo disponible de la categoria deseada devuekve NULL
		if (miVehiculo == NULL) {
			cout << "No hay vehiculos disponibles de la categoria solicitada" << endl;
			continue;
		}
		miAlquiler = new cAlquiler(fechaInicio, fechaFin, miCliente, miVehiculo);
		agregarElementosSeguridad(miAlquiler, miVehiculo);
		try {
			miEmpresa->nuevoAlquiler(miAlquiler); //Agregamos el alquiler a la lista de alquileres de la empresa
		}
		catch (exception* ex) {
			cout << ex->what() << endl; delete ex;
		}
		cantClientesAgregados++;
	}

}
void getFechasRandomNuevoAlquiler(cFecha* fechaInicio, cFecha* fechaFin) {
	//Definimos dos fechas posteriores a la actual para la de inicio y fin del alquiler
	if ((fechaInicio == NULL) || (fechaFin == NULL))
		return;
	fechaInicio->actualizarFecha(); fechaFin->actualizarFecha();
	short randomDiasInicio = rand() % 5 + 1; short randomMesesInicio = rand() % 2;
	short randomDiasDiferencia = rand() % 15 + 1; short randomMesesDiferencia = rand() % 2;
	fechaInicio->incrementarFecha(randomDiasInicio, randomMesesInicio);
	fechaFin->incrementarFecha(randomDiasInicio + randomDiasDiferencia, randomMesesInicio + randomMesesDiferencia);
}
void agregarElementosSeguridad(cAlquiler* miAlquiler, cVehiculo* miVehiculo) {
	//Recorremos y agregamos una cantidad random de los elementos de seguridad disponible 
	for (int i = 0; i < miVehiculo->getCantidadElementosSeguridad(); i++) {
		int elementoSeguridad = miAlquiler->getElementoSeguridad(i);
		int cantidadESagregar = rand() % 3; //si es más o menos de lo permitido, se arregla en agregarElementoSeguridad()
		miAlquiler->agregarElementoSeguridad(elementoSeguridad, cantidadESagregar);
	}
}
void mantenimientoVehiculoRandom(cEmpresa* miEmpresa) {
	//Llamamos al método mantenimiento de empresa para imprimir los pasos de mantenimiento de un vehiculo random 
	miEmpresa->mantenimiento(miEmpresa->getVehiculo(PATENTES[rand() % cantVehiculosAgregados]));
}
void imprimirFechaActual() {
	system("cls");
	cout << "\n\n\t\t\t[ " << fechaActual << " ]\n\n";
}
void diaSiguiente(cEmpresa* miEmpresa)
{// Incrementamos de a 1 dia la fecha actual 
	fechaActual->incrementarFecha(1);
	cListaAlquileres* alquileresQuitados = NULL;
	try {
		alquileresQuitados = miEmpresa->terminarAlquileres(fechaActual); //Terminamos los alquileres que tengan como fecha de fin del alquiler igual a la fecha actual
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
	}

	imprimirFechaActual();
	if (alquileresQuitados == NULL)
		cout << "\n\n\tNo hay ningun alquiler con fechaFin igual a la actual" << endl;
	else if (alquileresQuitados->getCA() == 0) {
		cout << "\n\n\tNo hay ningun alquiler con fechaFin igual a la actual" << endl;
		delete alquileresQuitados;
	}
	else {
		cout << "\n\n\tAlquileres finalizados hoy: \n" << alquileresQuitados->toString("\n\t") << endl; //Imprimimos los alquileres finalizados en la fecha 
		delete alquileresQuitados;
	}
	cout << endl << endl << "\tPresione una tecla para pasar al dia siguiente...";
	getchar();
}
