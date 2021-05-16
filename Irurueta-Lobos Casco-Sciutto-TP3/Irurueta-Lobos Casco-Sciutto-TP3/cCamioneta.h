#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{

public:
    cCamioneta();
    ~cCamioneta();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);
};

