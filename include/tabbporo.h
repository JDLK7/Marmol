#ifndef T_ABBPORO_H
#define T_ABBPORO_H

#include "tporo.h"
#include "tvectorporo.h"

class TNodoABB;

class TABBPoro {
	private:
		TNodoABB *nodo;
		void InordenAux(TVectorPoro &vector, const int &algo) const;
		void PreordenAux(TVectorPoro &vector, const int &algo) const;
		void PostordenAux(TVectorPoro &vector, const int &algo) const;
		void Copiar(const TABBPoro &arbol);
		TNodoABB * TABBPoro::MayorHijo() const;
	public:
		TABBPoro();
		TABBPoro(const TABBPoro &arbol);
		~TABBPoro();
		TABBPoro & operator=(const TABBPoro &arbol);
		bool operator==(const TABBPoro &arbol) const;
		bool operator!=(const TABBPoro &arbol) const;
		bool EsVacio() const;
		bool Insertar(const TPoro &poro);
		bool Borrar(const TPoro &poro);
		bool Buscar(const TPoro &poro);	//DEBERIA SER CONST
		bool Hoja() const;
		TPoro Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;
		TVectorPoro Inorden() const;
		TVectorPoro Preorden() const;
		TVectorPoro Postorden() const;
		TVectorPoro Niveles() const;
		TABBPoro operator+(const TABBPoro &arbol);
		TABBPoro operator+(const TABBPoro &arbol);
	friend ostream & operator<<(ostream &os, const TABBPoro &arbol);
};

class TNodoABB {
	private:
		TPoro item;
		TABBPoro iz, de;
	public:
		TNodoABB();
		TNodoABB(const TNodoABB &nodo);
		~TNodoABB();
		TNodoABB & operator=(const TNodoABB &nodo);
	friend class TABBPoro;
};

#endif // T_ABBPORO_H
