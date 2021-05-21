#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
#pragma region Constructor y Destructor
    cCamioneta(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
        string numeroPoliza = "", cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_CAMIONETAS,
        const unsigned int capacidadPasajeros = pasajerosMaxCAMIONETA, int cantElementosSeguridad = ESmaxCAMIONETA, float precioVehiculo = PrecioCompraCAMIONETA);
    ~cCamioneta();
#pragma endregion

#pragma region Getters
    string getTipoVehiculo();
    static string getPasosMantenimiento();
#pragma endregion
};

