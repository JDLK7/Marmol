#include "../include/tlistaporo.h"

TListaNodo::TListaNodo() : e() {
	anterior = NULL;
	siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &nodo) : e(nodo.e) {
	anterior = NULL;
	siguiente = NULL;
}

//No se tendria que hacer layering del destructor?
TListaNodo::~TListaNodo() : ~e() {
	anterior = NULL;
	siguiente = NULL;
}

TListaNodo & TListaNodo::operator=(const TListaNodo &nodo) {
	anterior = NULL;
	siguiente = NULL;
	e = nodo.e;
	return (*this);
}

////////////////////////////////////// TListaPosicion //////////////////////////////////////

TListaPosicion::TListaPosicion() {
	pos = NULL;
}

TListaPosicion::TListaPosicion(const TListaPosicion &origen) {
	pos = origen.pos;
}

TListaPosicion::~TListaPosicion() {
	pos = NULL;
}

TListaPosicion & TListaPosicion::operator=(const TListaPosicion &origen) {
	pos = origen.pos;
	return (*this);
}

bool TListaPosicion::operator==(const TListaPosicion &origen) const{
	return (pos==origen.pos);
}

TListaPosicion TListaPosicion::Anterior() const{
	TListaPosicion p;
	if(pos != NULL) {
		p.pos = pos->anterior;	
	}
	
	return p;
}

TListaPosicion TListaPosicion::Siguiente() const{
	TListaPosicion p;
	if(pos != NULL) {
		p.pos = pos->siguiente;	
	}
	
	return p;
}

bool TListaPosicion::EsVacia() const{
	if(pos == NULL) {
		return true;
	}
	else {
		return false;
	}
}

////////////////////////////////////// TListaPoro //////////////////////////////////////
void TListaPoro::InsertarCabeza(const TPoro &poro) {
	TListaNodo n;
	n.e = poro;
	n.siguiente = primero;
	primero = &n;
	n.anterior = NULL;
	n.siguiente->anterior = &n;
}

void TListaPoro::InsertarCola(const TPoro &poro) {
	TListaNodo n;
	n.e = poro;
	n.siguiente = NULL;
	n.anterior = ultimo;
	ultimo = &n;
	n.anterior->siguiente = &n;
}

void TListaPoro::InsertarEntre(const TPoro &poro, const TListaPosicion &p) {
	TListaNodo n;
	n.e = poro;
	n.siguiente = p.Siguiente().pos;
	n.anterior = p.pos;
	n.siguiente->anterior = &n;
	n.anterior->siguiente = &n;
}

TListaPoro::TListaPoro() {
	primero = NULL;
	ultimo = NULL;
}

TListaPoro::TListaPoro(const TListaPoro &lista) {

}

TListaPoro::~TListaPoro() {
	
}

TListaPoro & TListaPoro::operator=(const TListaPoro &lista) {

}

bool TListaPoro::operator==(const TListaPoro &lista) const{

}

TListaPoro TListaPoro::operator+(const TListaPoro &lista) {

}

TListaPoro TListaPoro::operator-(const TListaPoro &lista) {

}

bool TListaPoro::EsVacia() const{
	return (primero == NULL && ultimo == NULL);
}

bool TListaPoro::Insertar(const TPoro &poro) {
	if(!Buscar(poro)) {
		TListaPosicion p;
		double v, v1, v2;

		p.pos = primero;

		while(p.pos != NULL) {

			if(p.Siguiente().pos == NULL) {
				InsertarCola(poro);
				return true;
			}
			else {
				v = poro.Volumen();
				v1 = p.pos->e.Volumen();
				v2 = p.Siguiente().pos->e.Volumen();

				if(v < v1 && p.pos == primero) {
					InsertarCabeza(poro);
					return true;
				}
				else if(v >= v1 && v < v2){
					InsertarEntre(poro, p);
					return true;
				}
			}			

			p = p.Siguiente();
		}

		return false;
	}
	else {
		false;
	}
}

bool TListaPoro::Borrar(const TPoro &poro) {

}

bool TListaPoro::Borrar(const TListaPosicion &origen) {

}

TPoro TListaPoro::Obtener(const TListaPosicion &origen) const{
	if(origen.EsVacia()) {
		TPoro p;
		return p;
	}
	else {
		return origen.pos->e;
	}
}

//ESTO PUEDE ACABAR MAL XD
bool TListaPoro::Buscar(const TPoro &poro) const{
	if(!EsVacia()) {
		TListaPosicion p;
		p.pos = primero;

		while(true) {
			if(p.pos->e == poro) {
				return true;
			}
			else if(p.pos == ultimo) {
				return false;
			}

			p = p.Siguiente();
		}
	}
	else {
		return false;
	}
}

int TListaPoro::Longitud() const{
	if(!EsVacia()) {
		TListaPosicion p;
		p.pos = primero;

		int l = 0;

		while( !(p.pos == ultimo) ) {
			l++;
			p = p.Siguiente();
		}

		return l;
	}
	else {
		return 0;
	}
}

TListaPosicion TListaPoro::Primera() const{
	TListaPosicion p;

	if(!EsVacia()) {
		p.pos = primero;
	}

	return p;
}

TListaPosicion TListaPoro::Ultima() const{
	TListaPosicion p;

	if(!EsVacia()) {
		p.pos = ultimo;
	}

	return p;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2) {

}

ostream & operator<<(ostream &os,const TListaPoro &lista);