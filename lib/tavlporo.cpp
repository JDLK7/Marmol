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
void TAVLPoro::InordenAux(TVectorPoro &vector, int &pos) const {
	if(!EsVacio()) {
		raiz->iz.InordenAux(vector, pos);
		vector[pos] = raiz->item;
		pos++;
		raiz->de.InordenAux(vector, pos);
	}
}

void TAVLPoro::PreordenAux(TVectorPoro &vector, int &pos) const {
	if(raiz != NULL) {
		vector[pos] = raiz->item;
		pos++;
		raiz->iz.PreordenAux(vector, pos);
		raiz->de.PreordenAux(vector, pos);
	}
}

void TAVLPoro::PostordenAux(TVectorPoro &vector, int &pos) const {
	if(raiz != NULL) {
		raiz->iz.PostordenAux(vector, pos);
		raiz->de.PostordenAux(vector, pos);
		vector[pos] = raiz->item;
		pos++;
	}
}

void TAVLPoro::Copiar(const TAVLPoro &arbol) {
	if(arbol.raiz != NULL) {
		TNodoAVL *n = new TNodoAVL();
		n->item = arbol.raiz->item;

		raiz->fe = n->fe;
		
		raiz = n;
		(raiz->iz).Copiar(arbol.raiz->iz);
		(raiz->de).Copiar(arbol.raiz->de);
	}
	else {
		raiz = NULL;
	}
}

void TAVLPoro::Reequilibrar() {

}

TAVLPoro::TAVLPoro() {
	raiz = NULL;
}

TAVLPoro::TAVLPoro(const TAVLPoro &arbol) {
	Copiar(arbol);
}

TAVLPoro::~TAVLPoro() {
	if(raiz != NULL) {
		delete raiz;
		raiz = NULL;
	}
}

TAVLPoro & TAVLPoro::operator=(const TAVLPoro &arbol) {
	(*this).~TAVLPoro();
	Copiar(arbol);

	return (*this);
}

bool TAVLPoro::operator==(const TAVLPoro &arbol) const {
	if(arbol.Inorden() == Inorden()) {
		return true;
	}
	else {
		return false;
	}
}

bool TAVLPoro::operator!=(const TAVLPoro &arbol) const {
	return !((*this) == arbol);
}

bool TAVLPoro::EsVacio() const {
	return raiz == NULL;
}

bool TAVLPoro::Insertar(const TPoro &poro) {
	if(!EsVacio()) {
		double v = poro.Volumen();
		double vr = Raiz().Volumen();

		//No se pueden insertar duplicados.
		if(poro == raiz->item) {
			return false;
		}
	}
	else {
		raiz = new TNodoAVL();
		raiz->item = poro;
		raiz->fe = 0;

		return true;
	}
}

//Buscar no se si sirve.
bool TAVLPoro::Buscar(const TPoro &poro) const {
	if(!EsVacio()) {
		if(raiz->item == poro) {
			return true;
		}
		else {
			if(poro.Volumen() > raiz->item.Volumen()) {
				(raiz->de).Buscar(poro);
			}
			else {
				(raiz->iz).Buscar(poro);
			}
		}
	}
	else {
		return false;
	}
}

bool TAVLPoro::Hoja() const {
	if(raiz != NULL && raiz->iz.raiz == NULL && raiz->de.raiz == NULL) {
		return true;
	}

	return false;
}

int TAVLPoro::Altura() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else if(raiz->iz.Altura() > raiz->de.Altura()) {
			return (1 + raiz->iz.Altura());
		}
		else {
			return (1 + raiz->de.Altura());
		}
	}
	else {
		return 0;
	}
}

int TAVLPoro::Nodos() const {
	if(!EsVacio()) {
		return (1 + (raiz->de).Nodos() + (raiz->iz).Nodos());
	}
	else {
		return 0;
	}
}

int TAVLPoro::NodosHoja() const {
	if(!EsVacio()) {
		if(Hoja()) {
			return 1;
		}
		else {
			return ((raiz->de).NodosHoja() + (raiz->iz).NodosHoja());
		}
	}
	else {
		return 0;
	}
}

TVectorPoro TAVLPoro::Inorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());

	InordenAux(v, posicion);

	return v;
}

TVectorPoro TAVLPoro::Preorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);

	return v;
}

TVectorPoro TAVLPoro::Postorden() const {
	int posicion = 1;
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);

	return v;
}

bool TAVLPoro::Borrar(const TPoro &poro) {

}

TPoro TAVLPoro::Raiz() const {
	if(!EsVacio()) {
		return raiz->item;
	}
	else {
		TPoro error;
		return error;
	}
}

ostream & operator<<(ostream &os, const TAVLPoro &arbol) {
	os << arbol.Inorden();

	return os;
}