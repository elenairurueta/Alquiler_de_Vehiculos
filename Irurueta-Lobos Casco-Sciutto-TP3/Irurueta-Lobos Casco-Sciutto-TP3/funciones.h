#pragma once
#include "cEmpresa.h"
#include "datosVehiculos.h"
#include "datosClientes.h"

// variables goblales  
extern cFecha *fechaActual;
extern int cantVehiculosAgregados;
extern int cantClientesAgregados;

//Agregar 1 vehiculos de un tipo rad
void agregarVehiculos(int cantidad = 1, string tipo = "", cEmpresa* miEmpresa = NULL);
//Retiramos de la empresa un vehiculo random 
void retirarVehiculoRandom(cEmpresa* miEmpresa);
//Crea un nuevo alquiler junto con sus atributos 
void nuevosAlquileres(int cantidad, cEmpresa* miEmpresa);
void getFechasRandomNuevoAlquiler(cFecha* fechaInicio, cFecha* fechaFin);
//Agrega un numero random (dentro de lo permitido) de c/elemento de seguridad de la categoria
void agregarElementosSeguridad(cAlquiler* miAlquiler, cVehiculo* miVehiculo);
//Imprime los pasos de mantenimiento de un vehiculo random 
void mantenimientoVehiculoRandom(cEmpresa* miEmpresa);
void imprimirFechaActual();
//Pasa al siguiente dia y verifica cual es el alquiler que finaliza ese dia 
void diaSiguiente(cEmpresa* miEmpresa);