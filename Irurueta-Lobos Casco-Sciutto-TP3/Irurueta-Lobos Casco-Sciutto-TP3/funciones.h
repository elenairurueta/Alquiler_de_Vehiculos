#pragma once
#include "cEmpresa.h"
#include "datosVehiculos.h"
#include "datosClientes.h"

extern int cantVehiculosAgregados;
extern int cantClientesAgregados;

void agregarVehiculos(int cantidad = 1, string tipo = "", cEmpresa* miEmpresa = NULL);
void retirarVehiculoRandom(cEmpresa* miEmpresa);
void nuevosAlquileres(int cantidad, cEmpresa* miEmpresa);
void getFechasRandomNuevoAlquiler(cFecha& fechaInicio, cFecha& fechaFin);
void agregarElementosSeguridad(cAlquiler* miAlquiler, cVehiculo* miVehiculo);