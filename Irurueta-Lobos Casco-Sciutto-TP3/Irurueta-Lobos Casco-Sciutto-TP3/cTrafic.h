#pragma once
#include "cVehiculo.h"
class cTrafic :
    public cVehiculo
{

    cTrafic();
    ~cTrafic();
    string getTipoVehiculo();
    float calcularTarifa();

};

