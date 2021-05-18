#pragma once
#include <string>
using namespace std;
typedef enum {CASCO, SILLA_NINOS, PORTAEQUIPAJE, ASIENTOS_REVERSIBLES};
class cElementosSeguridad
{
	int tipo; //enum
	bool agregado;
	int cantidad;
public:
	cElementosSeguridad(int tipo, bool agregado = false, int cantidad = 0);
	~cElementosSeguridad();
	string getclave();
	void setCantidad(int cantidad);
	void setAgregado(bool agregado);
	string toString(string separador = "\n");
};