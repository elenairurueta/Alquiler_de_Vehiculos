#pragma once
#include "cAlquiler.h"
#include "cListaT.h"

#define TAM_A 10

class cListaAlquileres :
    public cListaT<cAlquiler>
{
public:
    cListaAlquileres(unsigned int TAM = TAM_A);
    ~cListaAlquileres();
    //imprime en pantalla los alquileres seg�n tipo de vehiculo
    void listarPorTipoVehiculo(); 
    //calcula la ganancia total de la lista de alquileres
    float calcularGananciaTotal();
    //devuelve true si el vehiculo pasado por par�metro se encuentra en alquiler, false si no
    bool chequearVehiculoEnAlquiler(cVehiculo* vehiculoBuscar = NULL, cFecha* fechaInicio = NULL, cFecha* fechaFin = NULL);
    //quita todos los alquileres cuya fecha de fin es la pasada por par�metro, y los devuelve en una lista de alquileres
    cListaAlquileres* quitarPorFecha(cFecha* fecha);
};

