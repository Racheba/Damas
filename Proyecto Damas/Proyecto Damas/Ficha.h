#include<iostream>
#include<sstream>
# define BLANCO 1
# define NEGRO 0

#pragma once
using namespace std;

class Ficha{
private:
	int color;
	//char tipo;
	bool esReina;

public:
	Ficha(int);
	Ficha(int, bool);
	~Ficha();

	void setColor(int );
	void setReina(bool);
	void setTipo(char);

	char getTipo();
	int getColor();
	bool FichaesReina();

	//imprimir
	string toString();

};