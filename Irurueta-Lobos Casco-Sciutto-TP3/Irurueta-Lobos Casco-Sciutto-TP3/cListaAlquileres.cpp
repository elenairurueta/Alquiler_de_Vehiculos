#include "cListaAlquileres.h"

cListaAlquileres::cListaAlquileres(unsigned int TAM):cListaT<cAlquiler>(TAM)
{
}

cListaAlquileres::~cListaAlquileres()
{
}

void cListaAlquileres::listarPorTipoVehiculo() 
{
	cout << "\n\nAlquileres por tipo de vehiculo";
	cout << "\n\n\tAutomoviles:" << endl;
	float ganancia = 0;
	for(int i = 0; i < CA; i++)
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "automovil"){
			ganancia += vector[i]->montoTotal;
			vector[i]->imprimir();
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl;

	ganancia = 0;
	cout << "\n\n\tMotocicletas:" << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "motocicleta") {
			ganancia += vector[i]->montoTotal;
			vector[i]->imprimir();
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl;

	ganancia = 0;
	cout << "\n\n\tCamionetas:" << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "camioneta") {
			ganancia += vector[i]->montoTotal;
			vector[i]->imprimir();
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl;

	ganancia = 0;
	cout << "\n\n\tTrafics:" << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "trafic") {
			ganancia += vector[i]->montoTotal;
			vector[i]->imprimir();
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl;

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

cListaAlquileres* cListaAlquileres::quitarPorFecha(cFecha* fecha)
{
	cListaAlquileres* alquileresQuitados = new cListaAlquileres();
	for (unsigned int i = 0; i < CA; i++){
		if (vector[i]->fechaFinReserva == NULL)
			continue;

		if (vector[i]->fechaFinReserva->compararDias(fecha) == 0)
		{
			alquileresQuitados->AgregarItem(QuitarenPos(i));
		}
	}
	return alquileresQuitados;
}
