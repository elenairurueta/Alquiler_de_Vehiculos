#pragma once
#include "cVehiculo.h"
class cAutomovil :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cAutomovil(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0,
        unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_AUTOMOVILES,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxAUTOMOVIL);
    ~cAutomovil();

    float calcularTarifa(int cantDias = 1);
    string getTipoVehiculo();
    int getCantidadElementosSeguridad();
};

