#pragma once
#include <string>
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
	cElementosSeguridad(int tipo, bool agregado = false, int cantidad = 0, float precio = 0);
	~cElementosSeguridad();
	string getclave();
	void setCantidad(int cantidad);
	void setAgregado(bool agregado);
	string toString(string separador = "\n");
	float getPrecioTotal();
	int getTipo();
};