#pragma once
#include "cAlquiler.h"
#include "cListaT.h"
#include "cVehiculo.h"
#include "cTrafic.h"

#define TAM_A 10

class cListaAlquileres :
    public cListaT<cAlquiler>
{

public:
    cListaAlquileres(unsigned int TAM = TAM_A);
    ~cListaAlquileres();
    void listarPorTipoVehiculo();
    float calcularGananciaTotal();

};

