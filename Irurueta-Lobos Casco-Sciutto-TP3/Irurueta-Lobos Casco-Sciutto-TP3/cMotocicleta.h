#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{
public:
    cMotocicleta();
    ~cMotocicleta();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);
};

