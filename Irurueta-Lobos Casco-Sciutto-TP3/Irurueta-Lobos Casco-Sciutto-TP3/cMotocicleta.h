#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{

    cMotocicleta();
    ~cMotocicleta();
    string getTipoVehiculo();
    float calcularTarifa();
};

