#include "../include/tavlporo.h"

//////////////////////////////////////////TNodoAVL//////////////////////////////////////////
TNodoAVL::TNodoAVL() : item(), iz(), de() {
	fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {
	fe = nodo.fe;
}

TNodoAVL::~TNodoAVL() {
	fe = 0;
}

TNodoAVL & TNodoAVL::operator=(const TNodoAVL &nodo) {
	if(this != &nodo) {
		item = nodo.item;

		if(nodo.iz.raiz != NULL && nodo.de.raiz != NULL) {
			iz = nodo.iz;
			de = nodo.de;
		}
		else {
			iz.raiz = NULL;
			de.raiz = NULL;
		}
	}

	return (*this);
}

//////////////////////////////////////////TAVLPoro//////////////////////////////////////////
TAVLPoro::TAVLPoro() {
	
}

TAVLPoro::TAVLPoro(const TAVLPoro &arbol) {

}

TAVLPoro::~TAVLPoro() {

}

TAVLPoro & TAVLPoro::operator=(const TAVLPoro &arbol) {

}

bool TAVLPoro::operator==(const TAVLPoro &arbol) const {

}

bool TAVLPoro::operator!=(const TAVLPoro &arbol) const {

}

bool TAVLPoro::EsVacio() const {

}

bool TAVLPoro::Insertar(const TPoro &poro) {

}

bool TAVLPoro::Buscar(const TPoro &poro) const {

}

int TAVLPoro::Altura() const {

}

int TAVLPoro::Nodos() const {

}

int TAVLPoro::NodosHoja() const {

}

TVectorPoro TAVLPoro::Inorden() const {

}

TVectorPoro TAVLPoro::Preorden() const {

}

TVectorPoro TAVLPoro::Postorden() const {

}

bool TAVLPoro::Borrar(const TPoro &poro) {

}

TPoro Raiz() const {

}

ostream & operator<<(ostream &os, const TAVLPoro &arbol) {

}