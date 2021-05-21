#include "cListaAlquileres.h"

cListaAlquileres::cListaAlquileres(unsigned int TAM):cListaT<cAlquiler>(TAM)
{
}

cListaAlquileres::~cListaAlquileres()
{
}

void cListaAlquileres::listarPorTipoVehiculo()
{
	cListaAlquileres* listaAutomoviles = new cListaAlquileres(CA);
	cListaAlquileres* listaMotocicletas = new cListaAlquileres(CA);
	cListaAlquileres* listaCamionetas = new cListaAlquileres(CA);
	cListaAlquileres* listaTrafics = new cListaAlquileres(CA);

	for(int i = 0; i < CA; i++)
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "automovil"){
			*listaAutomoviles += vector[i];
		}else if (vector[i]->vehiculo->getTipoVehiculo() == "camioneta") {
			*listaCamionetas += vector[i];

		}else if (vector[i]->vehiculo->getTipoVehiculo() == "motocicleta") {
			*listaMotocicletas += vector[i];

		}else if (vector[i]->vehiculo->getTipoVehiculo() == "trafic") {
			*listaTrafics += vector[i];

		}
	}

	cout << "\n\nAlquileres por tipo de vehiculo";
	cout << "\n\n\tAutomoviles:" << endl;
	listaAutomoviles->Listar("\n\n\t\t");
	cout << "\n\n\t\tGanancia: " << to_string(listaAutomoviles->calcularGananciaTotal()) << endl;

	cout << "\n\n\tMotocicletas:" << endl;
	listaMotocicletas->Listar("\n\n\t\t");
	cout << "\n\n\t\tGanancia: " << to_string(listaMotocicletas->calcularGananciaTotal()) << endl;

	cout << "\n\n\tCamionetas:" << endl;
	listaCamionetas->Listar("\n\n\t\t");
	cout << "\n\n\t\tGanancia: " << to_string(listaCamionetas->calcularGananciaTotal()) << endl;

	cout << "\n\n\tTrafics:" << endl;
	listaTrafics->Listar("\n\n\t\t");
	cout << "\n\n\t\tGanancia: " << to_string(listaTrafics->calcularGananciaTotal()) << endl;

	delete listaAutomoviles, listaMotocicletas, listaCamionetas, listaTrafics;
}

float cListaAlquileres::calcularGananciaTotal()
{
	float acumGanancias = 0;
	for (int i = 0; i < CA; i++)
		acumGanancias += vector[i]->montoTotal;
	return acumGanancias;
}

bool cListaAlquileres::chequearVehiculoEnAlquiler(cVehiculo* vehiculoBuscar)
{
	for (int i = 0; i < CA; i++) {
		if ((vector[i]->vehiculo->getclave()).compare(vehiculoBuscar->getclave()) == 0)
			return true;
	}
	return false;
}

void cListaAlquileres::quitarPorFecha(cFecha* fecha)
{
	cAlquiler* alquilerQuitado = NULL;
	for (unsigned int i = 0; i < CA; i++){
		if (vector[i]->fechaFinReserva.compararDias(fecha) == 0)
		{
			alquilerQuitado = QuitarenPos(i);
			if (alquilerQuitado != NULL)
				delete alquilerQuitado; //TODO ??
		}
	}
}
