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
    void listarPorTipoVehiculo(); 
    float calcularGananciaTotal();
    bool chequearVehiculoEnAlquiler(cVehiculo* vehiculoBuscar);
    void quitarPorFecha(cFecha* fecha);
};

