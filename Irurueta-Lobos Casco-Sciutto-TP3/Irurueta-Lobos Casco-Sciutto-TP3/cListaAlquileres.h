#pragma once
#include "cAlquiler.h"
#include "cListaT.h"
#include "cVehiculo.h"

//template <class T>
class cListaAlquileres :
    public cListaT<cAlquiler>
{

public:
    cListaAlquileres();
    ~cListaAlquileres();
    void listarPorTipoVehiculo();
    float calcularGananciaTotal(cListaT<cVehiculo> *lista);

};

