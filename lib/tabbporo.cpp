#include "../include/tabbporo.h"

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

bool TABBPoro::operator!=(const TABBPoro &arbol) const {
	return !(this==arbol);
}

bool TABBPoro::EsVacio() const {
	return Raiz.EsVacio();
}

bool TABBPoro::Insertar(const TPoro &poro) {
	//Arbol NO vacio
	if(nodo != NULL) {
		double v = poro.Volumen();
		double vr = Raiz().Volumen();

		//No se pueden insertar duplicados.
		if(v == vr) {
			return false;
		}
		else if(Hoja()) {
			if(v > vr) {
				nodo->de.nodo = new TNodoABB();
				nodo->de.nodo.item = poro;
			}
			else {
				nodo->iz.nodo = new TNodoABB();
				nodo->iz.nodo.item = poro;
			}
		}
		else {
			if(v > vr) {
				(nodo->de).Insertar(poro);
			}
			else {
				(nodo->iz).Insertar(poro);
			}
		}

	}
	else {
		nodo = new TNodoABB();
		nodo->item = poro;
	}

	return true;
}

bool TABBPoro::Borrar(const TPoro &poro) {

}

bool TABBPoro::Buscar(const TPoro &poro) {
	if(nodo != NULL) {
		TPoro p = nodo->item;

		if(p == poro) {
			return true;
		}
		else {
			if(poro.Volumen() > p.Volumen()) {
				(nodo->de).Buscar(poro);
			}
			else {
				(nodo->iz).Buscar(poro);
			}
		}

	}
	else {
		return false;
	}
}

bool TABBPoro::Hoja() const {
	if(nodo != NULL && nodo->iz.nodo == NULL && nodo->de.nodo == NULL) {
		return true;
	}

	return false;
}

TPoro TABBPoro::Raiz() const {
	if(nodo != NULL) {
		return nodo->item
	}
	else {
		TPoro error;
		return error;
	}
}
int TABBPoro::Altura() const {
	if(nodo->iz.nodo == NULL && nodo->de.nodo == NULL) {
		return 1
	}
	else {
		if(nodo->iz.Altura() > nodo->de.Altura()) {
			return (1 + nodo->iz.Altura());
		}
		else {
			return (1 + nodo->de.Altura());
		}
	}
}

int TABBPoro::Nodos() const {
	if(nodo != NULL) {
		return ((nodo->de).Nodos() + (nodo->iz).Nodos() + 1);
	}
	else {
		return 0;
	}
}

int TABBPoro::NodosHoja() const {
	if(nodo != NULL) {
		if(Hoja()) {
			return 1;
		}
		else {
			return ((nodo->de).NodosHoja() + (nodo->iz).NodosHoja());
		}
	}
	else {
		return 0;
	}
}

TVectorPoro TABBPoro::Inorden() const {
	TVectorPoro vector(Nodos());
	
}

TVectorPoro TABBPoro::Preorden() const {

}

TVectorPoro TABBPoro::Postorden() const {

}

TVectorPoro TABBPoro::Niveles() const {

}

TABBPoro TABBPoro::operator+(const TABBPoro &arbol) {

}

TABBPoro TABBPoro::operator+(const TABBPoro &arbol) {

}

ostream & TABBPoro::operator<<(ostream &os, const TABBPoro &arbol) {
	
}
