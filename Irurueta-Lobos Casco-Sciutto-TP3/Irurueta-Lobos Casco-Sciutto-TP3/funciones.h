#pragma once
#include "cEmpresa.h"
#include "datosVehiculos.h"
#include "datosClientes.h"

extern int cantVehiculosAgregados;

void agregarVehiculos(int cantidad = 1, string tipo = "", cEmpresa* miEmpresa = NULL);
void retirarVehiculoRandom(cEmpresa* miEmpresa);