#include"Ficha.h"


Ficha::Ficha(int x)
{
	color = x;
}
Ficha::Ficha(int x, bool reina)
{
	color = x;
	esReina = reina;
}
Ficha::~Ficha(){}

void Ficha::setColor(int x){ color = x; }
void Ficha::setReina(bool reina){ esReina = reina; }
//void Ficha::setTipo(char ){}

//char Ficha::getTipo(){}
int Ficha::getColor(){ return color; }
bool Ficha::FichaesReina(){ return esReina; }

//imprimir
string Ficha::toString()
{
	if (esReina && color == BLANCO) return " \x06 ";
	
	if (esReina && color == NEGRO) return "\x05";

	//--------------------------------------------------------------

	if (color == BLANCO) return " \x02 ";

	if (color == NEGRO) return " \x01 ";

}