#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{
    static string pasosMantenimiento;

public:
    cMotocicleta(string numeroPatente = "", unsigned int color = 0, string numeroChasis = "",
        string numeroPoliza = "", cFecha* ultimoMantenimiento = new cFecha(), float precioAlquilerXDia = ALQUILER_MOTOCICLETAS,
        const unsigned int capacidadPasajeros = 0, int cantElementosSeguridad = ESmaxMOTOCICLETA, float precioVehiculo = PrecioCompraMOTOCICLETA);
    ~cMotocicleta();
    string getTipoVehiculo();
    static string getPasosMantenimiento();

};

