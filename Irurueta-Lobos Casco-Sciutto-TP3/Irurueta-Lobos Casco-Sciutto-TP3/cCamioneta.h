#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cCamioneta(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0,
        unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_CAMIONETAS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxCAMIONETA);
    ~cCamioneta();
    string getTipoVehiculo();
    float calcularTarifa(int cantDias = 1);
    int getCantidadElementosSeguridad();

};

