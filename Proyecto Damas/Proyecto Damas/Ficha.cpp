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

	if (esReina && color == BLANCO) return " \x05 ";
	
	if (esReina && color == NEGRO) return "\x06";

	//-------------------------------

	if (color == BLANCO) return " \x01 ";

	if (color == NEGRO) return " \x02 ";

	// NEGRO 02, 06 BLANCO 01, 05	

}