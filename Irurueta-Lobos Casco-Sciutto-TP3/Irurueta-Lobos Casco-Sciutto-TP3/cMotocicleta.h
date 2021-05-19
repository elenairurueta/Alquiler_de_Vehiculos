#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cMotocicleta(unsigned int numeroPatente = 0, unsigned int color = 0, unsigned int numeroChasis = 0,
        unsigned int numeroPoliza = 0, cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_MOTOCICLETAS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxMOTOCICLETA, float precioVehiculo = PrecioCompraMOTOCICLETA);
    ~cMotocicleta();
    string getTipoVehiculo();
    static string getPasosMantenimiento();

};

