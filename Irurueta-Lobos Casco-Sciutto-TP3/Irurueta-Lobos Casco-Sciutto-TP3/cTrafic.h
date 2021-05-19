#pragma once
#include "cVehiculo.h"
class cTrafic :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cTrafic(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
        string numeroPoliza = "", cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_TRAFICS,
        const unsigned int capacidadPasajeros = pasajerosMaxTRAFIC, int cantElementosSeguridad = ESmaxTRAFIC, float precioVehiculo = PrecioCompraTRAFIC);
    ~cTrafic();
    string getTipoVehiculo();
    static string getPasosMantenimiento();

};

