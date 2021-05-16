#pragma once
#include "cVehiculo.h"
class cTrafic :
    public cVehiculo
{
public:
    cTrafic();
    ~cTrafic();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);

};

