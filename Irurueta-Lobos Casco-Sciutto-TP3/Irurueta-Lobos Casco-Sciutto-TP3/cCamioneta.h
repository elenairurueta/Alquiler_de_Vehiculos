#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cCamioneta(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
        string numeroPoliza = "", cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_CAMIONETAS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxCAMIONETA, float precioVehiculo = PrecioCompraCAMIONETA);
    ~cCamioneta();
    string getTipoVehiculo();
    static string getPasosMantenimiento();


};

