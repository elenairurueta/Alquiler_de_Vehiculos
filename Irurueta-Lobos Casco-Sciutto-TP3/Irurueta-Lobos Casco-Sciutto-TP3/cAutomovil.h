#pragma once
#include "cVehiculo.h"
class cAutomovil :
    public cVehiculo
{
public:
    cAutomovil();
    ~cAutomovil();

    float calcularTarifa(int cantDias = 1);
    string getTipoVehiculo();
};

