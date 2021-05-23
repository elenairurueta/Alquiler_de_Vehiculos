#pragma once
#include <string>
#include <iostream>
using namespace std;
typedef enum {CASCO, SILLA_NINOS, PORTAEQUIPAJE, ASIENTOS_REVERSIBLES};
class cElementosSeguridad
{
	friend class cListaElementosSeguridad;
	
	int tipo; //enum
	bool agregado;
	int cantidad;
	const float precio;

public:
	#pragma region Constructores y Destructores
	cElementosSeguridad(int tipo, bool agregado = false, int cantidad = 0, float precio = 0);
	~cElementosSeguridad();
	#pragma endregion
	
	#pragma region Getters
	string getclave();
	float getPrecioTotal();
	int getTipo();
	#pragma endregion
	
	#pragma region Setters
	void setCantidad(int cantidad);
	void setAgregado(bool agregado);
	#pragma endregion
	
	#pragma region toString() e imprimir()
	string toString(string separador = "\n");
	void imprimir(string separador = "\n");
	#pragma endregion
};
