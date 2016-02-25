#include "tvectorporo.h"

TVectorPoro::TVectorPoro() {
	dimension = 0;
	datos = NULL;
}

TVectorPoro::TVectorPoro(const int &dimension) {
	if(dimension <= 0) {
		this->dimension = 0;
		datos = NULL;
	}
	else {
		this->dimension = dimension;
		datos = new TPoro[dimension];
	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &vector) {
	dimension = vector.Longitud();
	datos = new TPoro[dimension];

	for(int i=0; i<dimension; i++) {
		datos[i] = vector[i+1];
	}
}

TVectorPoro::~TVectorPoro() {
	dimension = 0;
	if(datos!=NULL) {
		delete datos;
		datos = NULL;
	}
}

TVectorPoro & TVectorPoro::operator=(const TVectorPoro &vector) {
	(*this).~TVectorPoro();
	dimension = vector.Longitud();
	
	datos = new TPoro[dimension];
	for(int i=0; i<dimension; i++) {
		datos[i] = vector[i];
	}

	return *this;
}

bool TVectorPoro::operator==(const TVectorPoro &vector) const {
	bool igual=true;

	if(dimension == vector.Longitud()) {
		for(int i=0; i<dimension && igual; i++) {
			if(vector[i]!=datos[i]) {
				igual=false;
			}
		}
	}
	else {
		igual=false;
	}

	return igual;
}

bool TVectorPoro::operator!=(const TVectorPoro &vector) const {
	if((*this) == vector) {
		return true;
	}
	else {
		return false;
	}
}

bool TVectorPoro::Redimensionar(const int &tam) {
	if(tam <= 0) {
		return false;
	}
	else if(tam == dimension) {
		return false;
	}
	else if(tam > dimension) {
		//Guardamos los datos en un vector auxiliar.
		TPoro *aux = new TPoro[tam];
		for(int i=0; i<dimension; i++) {
			aux[i] = datos[i];
		}

		//Redimensionamos el array de partida.
		delete datos;
		datos = new TPoro[tam];

		for(int i=0; i<dimension; i++) {
			datos[i] = aux[i];
		}

		//Borramos el array auxiliar.
		delete aux;
		aux = NULL;

		return true;
	}
	else {	//Si tam < dimension
		TPoro *aux = new TPoro[tam];
		for(int i=0; i<tam; i++) {
			aux[i] = datos[i];
		}

		delete datos;
		datos = new TPoro[tam];

		for(int i=0; i<tam; i++) {
			datos[i] = aux[i];
		}

		return true;
	}

}

TPoro & TVectorPoro::operator[](const int &indice) {
	if(indice > 0) {
		return datos[indice - 1];
	}
	else {
		error;
		return error;
	}
}

//SE REPITE CODIGO----------------------------------------
TPoro TVectorPoro::operator[](const int &indice) const{
	if(indice > 0) {
		return datos[indice - 1];
	}
	else {
		return error;
	}
}


ostream & operator<<(ostream &os, TVectorPoro &vector) {
	os << "[";
	for(int i=0; i<vector.dimension; i++) {
		os << vector[i] << " ";
	}

	return os;
}