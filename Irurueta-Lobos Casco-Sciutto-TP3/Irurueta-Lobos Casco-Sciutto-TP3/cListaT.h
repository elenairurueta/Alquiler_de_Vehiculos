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

	void Listar(string separador = "");
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();
	T* &operator[](unsigned int pos) {
		if (pos < CA)
			return vector[pos];
		return NULL;
	}
	
};


