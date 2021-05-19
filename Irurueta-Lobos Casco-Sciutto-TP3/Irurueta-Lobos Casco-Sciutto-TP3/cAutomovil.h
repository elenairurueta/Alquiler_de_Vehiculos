#pragma once
#include "cVehiculo.h"
class cAutomovil :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cAutomovil(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
        string numeroPoliza = "", cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_AUTOMOVILES,
        const unsigned int capacidadPasajeros = pasajerosMaxAUTOMOVIL, int cantElementosSeguridad = ESmaxAUTOMOVIL, float precioVehiculo = PrecioCompraAUTOMOVIL);
    ~cAutomovil();
    string getTipoVehiculo();
    static string getPasosMantenimiento();

};

