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
	for(int i = 0; i < CA; i++) //buscamos los automoviles
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "automovil"){
			ganancia += vector[i]->montoTotal; //aumentamos el acumulador de ganancia de automoviles
			vector[i]->imprimir(); //y lo imprimimos
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl; //imprimimos la ganancia total de automoviles

	ganancia = 0;
	cout << "\n\n\tMotocicletas:" << endl;
	for (int i = 0; i < CA; i++) //buscamos las motocicletas
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "motocicleta") {
			ganancia += vector[i]->montoTotal; //aumentamos el acumulador de ganancia de automoviles
			vector[i]->imprimir(); //y lo imprimimos
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl; //imprimimos la ganancia total de automoviles

	ganancia = 0;
	cout << "\n\n\tCamionetas:" << endl;
	for (int i = 0; i < CA; i++) //buscamos las camionetas
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "camioneta") {
			ganancia += vector[i]->montoTotal; //aumentamos el acumulador de ganancia de camionetas
			vector[i]->imprimir(); //y lo imprimimos
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl; //imprimimos la ganancia total de automoviles

	ganancia = 0;
	cout << "\n\n\tTrafics:" << endl;
	for (int i = 0; i < CA; i++) //buscamos las trafics
	{
		if (vector[i]->vehiculo->getTipoVehiculo() == "trafic") {
			ganancia += vector[i]->montoTotal; //aumentamos el acumulador de ganancia de trafics
			vector[i]->imprimir(); //y lo imprimimos
		}
	}
	cout << "\n\n\t\tGanancia: " << to_string(ganancia) << endl; //imprimimos la ganancia total de automoviles

}

float cListaAlquileres::calcularGananciaTotal()
{
	float acumGanancias = 0;
	for (int i = 0; i < CA; i++) //recorremos toda la lista de alquileres
		acumGanancias += vector[i]->montoTotal; //y acumulamos todos los montos totales
	return acumGanancias; //para calcular la ganancia total de la lista de alquileres actual
}

bool cListaAlquileres::chequearVehiculoEnAlquiler(cVehiculo* vehiculoBuscar)
{
	for (int i = 0; i < CA; i++) {
		if ((vector[i]->vehiculo->getclave()).compare(vehiculoBuscar->getclave()) == 0) //si encontramos el vehiculo en la lista de alquileres
			return true; //el vehiculo est� en alquiler
	}
	return false; //si no lo encontramos, no est� en alquiler
}

cListaAlquileres* cListaAlquileres::quitarPorFecha(cFecha* fecha) 
{
	cListaAlquileres* alquileresQuitados = new cListaAlquileres();  //creamos una lista de alquileres para agregar los alquileres quitados
	for (unsigned int i = 0; i < CA; i++){ //recorremos la lista de alquileres
		if (vector[i]->fechaFinReserva == NULL)
			continue;

		if (vector[i]->fechaFinReserva->compararDias(fecha) == 0) //si encontramos un alquiler cuya fecha fin es la pasada por par�metro
		{
			alquileresQuitados->AgregarItem(QuitarenPos(i)); //lo quitamos de la lista de alquileres actual y lo agregamos a la lista de alquileres quitados
		}
	}
	return alquileresQuitados;
}
