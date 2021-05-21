#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class cFecha
{
private:
#pragma region Atributos
	short hora;
	short minutos;
	short segundos;
	short dia;
	short mes;
	short anio;
#pragma endregion
public:
#pragma region Constructores y Destructores
	cFecha(short hora = 0, short minutos = 0, short segundos = 0, short dia = 0, short mes = 0, short anio = 0);
	~cFecha();
#pragma endregion

#pragma region Metodos
	//convierte todos los atributos de la clase en string
	string toString(string separador = "-");
	//imprime todos los atributos de la clase
	void imprimir();
	//actualiza la fecha a la actual
	void actualizarFecha();
	//devuelve -1 si fechaComparar es m�s antigua, 1 si es m�s reciente y 0 si son iguales
	int compararFechas(cFecha* fechaComparar);
	//devuelve la cantidad de d�as que pasaron entre una fecha y la otra (redondeando para arriba)
	unsigned int calcularDiasDiferencia(cFecha* fechaComparar);
	void incrementarFecha(short dia = 0, short mes = 0, short anio = 0, short hora = 0, short minutos = 0, short segundos = 0);

private:
	//verifica que la fecha sea factible
	void verificarFecha();
#pragma endregion
};