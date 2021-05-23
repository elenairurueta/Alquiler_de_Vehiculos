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
    //calcula el costo total de los elementos de seguridad para la cantidad de d�as pasada por par�metro
    float calcularTarifa(unsigned int dias);
};

