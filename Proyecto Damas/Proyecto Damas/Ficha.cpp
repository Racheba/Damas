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

	if (esReina == true && color == 1)
		return "N";
	
	if (esReina == true && color == 0)
			return "B";

	//-------------------------------
	if (color == 1)
	{
		return "n";
	}
	else
		if (color == 0)
		return "b";


	

}