#pragma once
#include "cVehiculo.h"
class cAutomovil :
    public cVehiculo
{
    cAutomovil();
    ~cAutomovil();

    float calcularTarifa();
    string getTipoVehiculo();
};

