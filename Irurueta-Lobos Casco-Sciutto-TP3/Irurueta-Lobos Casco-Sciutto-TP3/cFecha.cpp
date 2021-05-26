#define _CRT_SECURE_NO_WARNINGS
#include "cFecha.h"
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
	if (fechaComparar == NULL)
		return -2;
	if ((this->anio) > fechaComparar->anio)
		return -1;
	else if ((this->anio) < fechaComparar->anio)
		return 1;
	else if ((this->anio) == fechaComparar->anio)
	{
		if ((this->mes) > fechaComparar->mes)
			return -1;
		else if ((this->mes) < fechaComparar->mes)
			return 1;
		else if ((this->mes) == fechaComparar->mes)
		{
			if ((this->dia) > fechaComparar->dia)
				return -1;
			else if ((this->dia) < fechaComparar->dia)
				return 1;
			else if ((this->dia) == fechaComparar->dia)
			{
				if ((this->hora) > fechaComparar->hora)
					return -1;
				else if ((this->hora) < fechaComparar->hora)
					return 1;
				else if ((this->hora) == fechaComparar->hora)
				{
					if ((this->minutos) > fechaComparar->minutos)
						return -1;
					else if ((this->minutos) < fechaComparar->minutos)
						return 1;
					else if ((this->minutos) == fechaComparar->minutos)
					{
						if ((this->segundos) > fechaComparar->segundos)
							return -1;
						else if ((this->segundos) < fechaComparar->segundos)
							return 1;
						else if ((this->segundos) == fechaComparar->segundos)
							return 0;
					}
				}
			}
		}
	}
	return -2;
}

int cFecha::compararDias(cFecha* fechaComparar)
{
	if (fechaComparar == NULL)
		return -2;
	if ((this->anio) > fechaComparar->anio)
		return -1;
	else if ((this->anio) < fechaComparar->anio)
		return 1;
	else if ((this->anio) == fechaComparar->anio)
	{
		if ((this->mes) > fechaComparar->mes)
			return -1;
		else if ((this->mes) < fechaComparar->mes)
			return 1;
		else if ((this->mes) == fechaComparar->mes)
		{
			if ((this->dia) > fechaComparar->dia)
				return -1;
			else if ((this->dia) < fechaComparar->dia)
				return 1;
			else if ((this->dia) == fechaComparar->dia)
			{
				return 0;				
			}
		}
	}
	return -2;
}

unsigned int cFecha::calcularDiasDiferencia(cFecha* fechaComparar)
{ 
	if (compararFechas(fechaComparar) == 0)
		return 0;
	time_t t = time(0);
	struct tm* fechaInstanciaActual = localtime(&t);
	fechaInstanciaActual->tm_year = this->anio-1900;
	fechaInstanciaActual->tm_mon = this->mes-1;
	fechaInstanciaActual->tm_mday = this->dia;
	fechaInstanciaActual->tm_hour = this->hora;
	fechaInstanciaActual->tm_min = this->minutos;
	fechaInstanciaActual->tm_sec = this->segundos;
	fechaInstanciaActual->tm_wday = 0;
	fechaInstanciaActual->tm_yday = 0;
	fechaInstanciaActual->tm_isdst = 0;

	struct tm* fechaComparacion = localtime(&t);
	fechaComparacion->tm_year = int(fechaComparar->anio)-1900;
	fechaComparacion->tm_mon = int(fechaComparar->mes)-1;
	fechaComparacion->tm_mday = int(fechaComparar->dia);
	fechaComparacion->tm_hour = int(fechaComparar->hora);
	fechaComparacion->tm_min = int(fechaComparar->minutos);
	fechaComparacion->tm_sec = int(fechaComparar->segundos);
	fechaComparacion->tm_wday = 0;
	fechaComparacion->tm_yday = 0;
	fechaComparacion->tm_isdst = 0;

	time_t fechaComparacion2 = mktime(fechaComparacion);
	time_t fechaActual2 = mktime(fechaInstanciaActual);
	double dias = difftime(fechaComparacion2, fechaActual2) / (60 * 60 * 24);
	dias++;
	return unsigned int(dias);
}

void cFecha::incrementarFecha(short dia, short mes, short anio)
{
	switch (this->mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (dia > 31) //verificacion de lo pasado por parámetro (no más de un mes en dias)
			dia = 31;
		if ((this->dia + dia) > 31)
		{
			this->dia += dia - 31;
			if (this->mes == 12) {
				this->anio++;
				this->mes = 1;
			}
			else
				this->mes++;
		}
		else
			this->dia += dia;
		break;
	case 2:
		if (dia > 28) //verificacion de lo pasado por parámetro (no más de un mes en dias)
			dia = 28;
		if ((this->dia + dia) > 28)
		{
			this->dia += dia - 28;
			this->mes++;
		}
		else
			this->dia += dia;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (dia > 30) //verificacion de lo pasado por parámetro (no más de un mes en dias)
			dia = 30;
		if ((this->dia + dia) > 30)
		{
			this->dia += dia - 28;
			this->mes++;
		}
		else
			this->dia += dia;
		break;
	default:
		break;
	}
	if ((this->mes + mes) > 12)
	{
		this->anio++;
		this->mes += mes - 12;
	}
	else
		this->mes += mes;
	this->anio += anio;
	verificarFecha();

}

#pragma region toString e Imprimir
string cFecha::toString(string separador, bool conHora)
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
	fechaStr += "/" + to_string(anio);

	if(conHora == false) return fechaStr;


	fechaStr += separador;
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

bool cFecha::operator>(cFecha* derecha) {
	if (compararFechas(derecha) == -1)
		return true;
	else
		return false;
}
ostream& operator<<(ostream& os, cFecha* fecha)
{
	os << fecha->toString();
	return os;
}