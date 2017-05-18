#include"Casilla.h"

Casilla::Casilla(char d, int f, int c)
{
	dato = d;
	fila = f;
	colum = c;

	upR = NULL;
	upL = NULL;
	downR = NULL;
	downL = NULL;
}

Casilla::~Casilla(){}

char Casilla::getDato(){ return dato; }
int Casilla::getColumna(){ return colum; }
int Casilla::getFila(){ return fila; }
Ficha* Casilla::getFicha(){ return ficha; }

Casilla* Casilla::getUpR(){ return upR; }
Casilla* Casilla::getUpL(){ return upL; }
Casilla* Casilla::getDownR(){ return downR; }
Casilla* Casilla::getDownL(){ return downL; }

void Casilla::setDato(char d){ dato = d; }
void Casilla::setUpR(Casilla* ur){ upR = ur; }
void Casilla::setUpL(Casilla* ul){ upL = ul; }
void Casilla::setDownR(Casilla* dr){ downR = dr; }
void Casilla::setDownL(Casilla* dl){ downL = dl; }
void Casilla::setFicha(Ficha* f){ ficha = f; }

string Casilla::toString() //cambiar la casilla
{
	stringstream s;

	s << "[" << getFila() << "," << getColumna() << "]" << endl;

	return s.str();
}



