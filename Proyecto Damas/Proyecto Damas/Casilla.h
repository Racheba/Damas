#include<iostream>
#include<sstream>
#include"Ficha.h"
using namespace std;

class Casilla{
private:
	char dato;
	int fila;
	int colum;

	Casilla* upR;
	Casilla* upL;
	Casilla* downR;
	Casilla* downL;

	Ficha* ficha;

public:

	Casilla(Ficha* fi, int, int);
	~Casilla();

	//int getDato();
	int getColumna();
	int getFila();
	Ficha* getFicha();

	Casilla* getUpR();
	Casilla* getUpL();
	Casilla* getDownR();
	Casilla* getDownL();


//	void setDato(int);
	void setUpR(Casilla*);
	void setUpL(Casilla*);
	void setDownR(Casilla*);
	void setDownL(Casilla*);
	void setFicha(Ficha* );

	string toString();



};