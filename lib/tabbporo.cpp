#include "tabbporo.h"

TNodoABB::TNodoABB() : item(), iz(), de() {

}

TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {

}

TNodoABB::~TNodoABB() {

}

TNodoABB & TNodoABB::operator=(const TNodoABB &nodo) {
	if(this != nodo) {
		~TNodoABB();

		item = nodo.item;
		iz = nodo.iz;
		de = nodo.de;
	}

	return this;
}

//////////////////////////////// TABBPoro ////////////////////////////////
void TABBPoro::Copiar(const TABBPoro &arbol) {
	if(arbol.nodo != NULL) {
		TNodoABB *n = new TNodoABB();
		n->item = arbol.nodo->item;
		nodo = n;
		(nodo->iz).Copiar(arbol.nodo->iz);
		(nodo->de).Copiar(arbol.nodo->de);
	}
	else {
		nodo = NULL;
	}
}

TABBPoro::TABBPoro() {
	nodo = new TNodoABB();
}
TABBPoro::TABBPoro(const TABBPoro &arbol) {
	Copiar(arbol);
}
TABBPoro::~TABBPoro() {
	if(nodo != NULL) {
		delete nodo;
		nodo = NULL;
	}
}

TABBPoro & TABBPoro::operator=(const TABBPoro &arbol) {
	~TABBPoro();
	Copiar(arbol);

	return (*this);
}

bool TABBPoro::operator==(const TABBPoro &arbol) const {
	if(!Raiz().EsVacio() && !arbol.Raiz().EsVacio()) {
		if(Raiz() == arbol.Raiz()) {
			return ((nodo->iz == arbol.nodo->iz) && (nodo->de == arbol.nodo->de));
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

bool TABBPoro::EsVacio() const {
	return Raiz.EsVacio();
}

bool TABBPoro::Borrar(const TPoro &poro);
bool TABBPoro::Buscar(const TPoro &poro);
TPoro TABBPoro::Raiz() const {
	if(nodo != NULL) {
		return nodo->item
	}
	else {
		TPoro error;
		return error;
	}
}
int TABBPoro::Altura() const;
int TABBPoro::Nodos() const;
int TABBPoro::NodosHoja() const;
TVectorPoro TABBPoro::Inorden() const;
TVectorPoro TABBPoro::Preorden() const;
TVectorPoro TABBPoro::Postorden() const;
TVectorPoro TABBPoro::Niveles() const;
TABBPoro TABBPoro::operator+(const TABBPoro &arbol);
TABBPoro TABBPoro::operator+(const TABBPoro &arbol);
ostream & TABBPoro::operator<<(ostream &os, const TABBPoro &arbol);
