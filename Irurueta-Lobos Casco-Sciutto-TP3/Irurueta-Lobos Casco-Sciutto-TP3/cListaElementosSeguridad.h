#pragma once
#include "cListaT.h"
#include "cElementosSeguridad.h"
#include "defines.h"
class cListaElementosSeguridad :
    public cListaT<cElementosSeguridad>
{
    friend class cAlquiler;
public:
    cListaElementosSeguridad(string tipoVehiculo, int cantidadElementos);
    ~cListaElementosSeguridad();
    float calcularTarifa(unsigned int dias);
};

