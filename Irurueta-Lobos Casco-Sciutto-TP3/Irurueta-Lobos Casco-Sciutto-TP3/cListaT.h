#pragma once
#define NMAX 10

#include <string>

using namespace std;
template<class T>
class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;

	void Redimensionalizar(int cant);

public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T* item);
	bool AgregarItemOrdenado(const T* item);

	T* Quitar(string clave);
	T* Quitar(const T* item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void Eliminar(const T* item);
	void Eliminar(unsigned int pos);

	void Listar();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();
};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}
template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}
template<class T>
void cListaT<T>::Redimensionalizar(int cant)
{
	if (cant <= 0) //verificamos que la lista se esté agrandando
		return;
	//creamos un nuevo puntero doble con su lista dinámica (de tamaño TAM+cant) de punteros
	T** auxiliar = new T * [TAM + cant]();
	for (int i = 0; i < (TAM + cant); i++)
	{
		if (i < CA) //hacemos que los primeros CA nuevos punteros apunten a la misma direccion que los que tenemos
		{
			auxiliar[i] = vector[i];
		}
		else //y que el resto queden apuntados a NULL
			auxiliar[i] = NULL;
	}
	delete[] vector; //eliminamos la lista dinámica de punteros anterior
	vector = auxiliar; //y le asignamos la nueva lista al doble puntero
	auxiliar = NULL;
	TAM += cant; //aumentamos el contador de tamaño disponible
}


template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;
}
template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}
}

template<class T>
void cListaT<T>::Listar()
{
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();
	}
}
template<class T>
bool cListaT<T>::AgregarItem(T* item)
{
	T* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tamanio suficiente para agregar el item");;
	return true;
}
template<class T>
bool cListaT<T>::AgregarItemOrdenado(const T* item)
{
	/*for (unsigned int i = 0; i < CA; i++)
	{
	if (vector[i]->getclave() == clave)
	return vector[i];
	}
	*/
	return false;
} 
//borrar?

template<class T>
T* cListaT<T>::Quitar(string clave) {

	unsigned int pos = getItemPos(clave);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}
template<class T>
T* cListaT<T>::Quitar(const T* item) {
	unsigned int pos = getItemPos(item->getclave());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}
template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	T* aux = vector[pos];

	for (unsigned int i = 0; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}

template<class T>
void cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);

	if (pos < CA)
		Eliminar(pos);
	//sino algo

}
template<class T>
void cListaT<T>::Eliminar(const T* item) {

	Eliminar(item->getclave());
}
template<class T>
void cListaT<T>::Eliminar(unsigned int pos) {
	if (pos >= CA)return;// o Throw no pude eliminar

	T* dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
	else
	{
		throw new exception("no encontrado");
	}
}

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return vector[i];
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}
template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return i;
	}

	return INT_MAX;
}



