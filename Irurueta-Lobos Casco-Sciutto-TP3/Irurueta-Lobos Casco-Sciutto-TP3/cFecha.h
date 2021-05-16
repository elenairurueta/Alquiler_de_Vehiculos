#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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
	string toString();
	//imprime todos los atributos de la clase
	void imprimir();
	//actualiza la fecha a la actual
	void actualizarFecha();
	//devuelve -1 si fechaComparar es más antigua, 1 si es más reciente y 0 si son iguales
	int compararFechas(cFecha* fechaComparar);
private:
	//verifica que la fecha sea factible
	void verificarFecha();
#pragma endregion
};

#pragma region Constructores y Destructores
cFecha::cFecha(short hora, short minutos, short segundos, short dia, short mes, short anio) {
	this->hora = hora;
	this->minutos = minutos;
	this->segundos = segundos;
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	verificarFecha();
}
cFecha::~cFecha()
{
}
#pragma endregion

void cFecha::verificarFecha()
{
	if (hora >= 24)
		hora = 23;
	if (minutos >= 60)
		minutos = 59;
	if (segundos >= 60)
		segundos = 59;
	if (mes > 12)
		mes = 12;
	if (mes <= 0)
		mes = 1;
	switch (mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (dia > 31)
			dia = 31;
		break;
	case 2:
		if (dia > 28)
			dia = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (dia > 30)
			dia = 30;
		break;
	default:
		break;
	}
	if (anio > 2021)
		anio = 2021;
}
void cFecha::actualizarFecha()
{
	time_t now = time(0);
	tm* currentdate = localtime(&now);
	this->anio = short(currentdate->tm_year) + 1900;
	this->mes = short(currentdate->tm_mon) + 1;
	this->dia = short(currentdate->tm_mday);
	this->hora = short(currentdate->tm_hour);
	this->minutos = short(currentdate->tm_min);
	this->segundos = short(currentdate->tm_sec);
}
int cFecha::compararFechas(cFecha* fechaComparar)
{
	if (anio > fechaComparar->anio)
		return -1;
	else if (anio < fechaComparar->anio)
		return 1;
	else if (anio == fechaComparar->anio)
	{
		if (mes > fechaComparar->mes)
			return -1;
		else if (mes < fechaComparar->mes)
			return 1;
		else if (mes == fechaComparar->mes)
		{
			if (dia > fechaComparar->dia)
				return -1;
			else if (dia < fechaComparar->dia)
				return 1;
			else if (dia == fechaComparar->dia)
			{
				if (hora > fechaComparar->hora)
					return -1;
				else if (hora < fechaComparar->hora)
					return 1;
				else if (hora == fechaComparar->hora)
				{
					if (minutos > fechaComparar->minutos)
						return -1;
					else if (minutos < fechaComparar->minutos)
						return 1;
					else if (minutos == fechaComparar->minutos)
					{
						if (segundos > fechaComparar->segundos)
							return -1;
						else if (segundos < fechaComparar->segundos)
							return 1;
						else if (segundos == fechaComparar->segundos)
							return 0;
					}
				}
			}
		}
	}
	return -2;
}

#pragma region toString e Imprimir
string cFecha::toString()
{
	string fechaStr = "";
	if (dia < 10) {
		fechaStr += "0" + to_string(dia);
	}
	else {
		fechaStr += to_string(dia);
	}
	fechaStr += "/";
	if (mes < 10) {
		fechaStr += "0" + to_string(mes);
	}
	else {
		fechaStr += to_string(mes);
	}
	fechaStr += "/" + to_string(anio) + " - ";

	if (hora < 10) {
		fechaStr += "0" + to_string(hora);
	}
	else {
		fechaStr += to_string(hora);
	}
	fechaStr += ":";
	if (minutos < 10) {
		fechaStr += "0" + to_string(minutos);
	}
	else {
		fechaStr += to_string(minutos);
	}
	fechaStr += ":";
	if (segundos < 10) {
		fechaStr += "0" + to_string(segundos);
	}
	else {
		fechaStr += to_string(segundos);
	}
	return fechaStr;
}
void cFecha::imprimir()
{
	cout << toString() << endl;
}
#pragma endregion
