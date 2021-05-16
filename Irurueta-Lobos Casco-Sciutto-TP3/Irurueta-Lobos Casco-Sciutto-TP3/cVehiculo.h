#pragma once
template<class T>
class cVehiculo
{
protected:
	const unsigned int numeroPatente;
	const unsigned int color;
	const unsigned int numeroChasis;
	const unsigned int numeroPoliza;
	cFecha* ultimoMantenimiento;
	float precioAlquilerXDia;
	const unsigned int capacidadPasajeros;
	T* elementosSeguridad;

public:
	cVehiculo();
	virtual ~cVehiculo();
	virtual float calcularTarifa() = 0;

};