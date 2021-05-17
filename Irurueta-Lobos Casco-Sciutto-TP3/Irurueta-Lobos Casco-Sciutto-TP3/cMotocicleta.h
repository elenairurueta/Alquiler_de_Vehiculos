#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{
public:
    cMotocicleta(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0,
        unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_MOTOCICLETAS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = 0, string elementosSeguridad = "");
    ~cMotocicleta();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);
};

