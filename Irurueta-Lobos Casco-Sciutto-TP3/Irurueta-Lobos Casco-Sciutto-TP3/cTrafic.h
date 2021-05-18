#pragma once
#include "cVehiculo.h"
class cTrafic :
    public cVehiculo
{
public:
    cTrafic(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0,
        unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_TRAFICS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxTRAFIC);
    ~cTrafic();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);
    int getCantidadElementosSeguridad();

};

