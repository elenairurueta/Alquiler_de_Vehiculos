#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{
    cCamioneta();
    ~cCamioneta();
    string getTipoVehiculo();
    float calcularTarifa();
};

