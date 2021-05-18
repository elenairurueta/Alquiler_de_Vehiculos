#pragma once
#include "cListaT.h"
#include "cElementosSeguridad.h"
class cListaElementosSeguridad :
    public cListaT<cElementosSeguridad>
{
public:
    cListaElementosSeguridad(string tipoVehiculo, int cantidadElementos);
    ~cListaElementosSeguridad();
};

