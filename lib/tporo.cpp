#include "tporo.h"

using namespace std;

void TPoro::toLower(char *color)
{
	for (unsigned int i = 0; i < strlen(color); i++) {
		if (color[i] >= 'A' && color[i] <= 'Z') {
			color[i] += 32;
		}
	}
}

TPoro::TPoro() {
	x = 0;
	y = 0;
	volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, char *color) {
	this->x = x;
	this->y = y;
	this->volumen = volumen;

	this->color = new char[strlen(color)+1];
	strcpy(this->color,color);
	
	toLower(color);
}

TPoro::TPoro(const TPoro &poro)
{
	x = poro.PosicionX();
	y = poro.PosicionY();
	volumen = poro.Volumen();
	color = new char[strlen(poro.Color())+1];
	strcpy(color, poro.Color());
}

TPoro::~TPoro()
{
	x = 0;
	y = 0;
	volumen = 0;
	if (color != NULL) {
		delete color;
		color = NULL;
	}
}

TPoro & TPoro::operator=(const TPoro &poro)
{
	(*this).~TPoro();
	x = poro.PosicionX();
	y = poro.PosicionY();
	volumen = poro.Volumen();
	color = new char[strlen(poro.Color())+1];
	color = strcpy(color, poro.Color());

	return (*this);
}

bool TPoro::operator==(const TPoro & poro) const
{
	if (this->PosicionX() == poro.PosicionX() && this->PosicionY() == poro.PosicionY() && volumen == poro.Volumen()) {
		//Lio de punteros.
		if ((*color) == (*poro.Color())) {
			return true;
		}
	}
	return false;
}

bool TPoro::operator!=(const TPoro & poro) const
{
	//Supongo que hay que poner el contenido de this porque this es un puntero que señala a "este" objeto.
	if ((*this) == poro) {
		return false;
	}
	return true;
}

bool TPoro::EsVacio() const
{
	if (x == 0 && y == 0 && volumen == 0 && color == NULL) {
		return true;
	}
	return false;
}

/*Al ser una funcion amiga, deja acceder a los atributos privados
 *por lo tanto no hace falta utilizar los getters.
 */
ostream & operator<<(ostream & os, TPoro & poro)
{
	if (!poro.EsVacio()) {
		//Fijar precision 2 decimales;
		os.setf(ios::fixed);
		os.precision(2);

		os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";
		if (poro.color != NULL) {
			os << poro.color;
		}
		else {
			os << "-";
		}
	}
	else {
		os << "()";
	}
	return os;
}
