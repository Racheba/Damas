#include"Jugador.h"

Jugador::Jugador(/*int col */ int fichas, char t)
{
	//color = col;
	cantFichas = fichas;
	tipo = t;
}
Jugador::~Jugador(){}

int Jugador::getcantFichas(){ return cantFichas; }
int Jugador::getColor(){ return color; }
int Jugador::getReinas(){ return cantReinas; }

void Jugador::setCantFichas(int x){ cantFichas = x; }
void Jugador::setColor(int y){ color = y; }
void Jugador::setReinas(int z){ cantReinas = z; }

bool Jugador::SinFichas()
{
	if (cantFichas == 0)
		return false;
	else
	{
		cantFichas--;
		return true;
	}
}

string Jugador::perdio(Jugador* jugador1, Jugador* jugador2)
{
	stringstream s;

	if (jugador1->cantFichas == 0)
		s << " -> Fichas blancas perdieron." << endl;

	if (jugador2->cantFichas == 0)
		s << " -> Fichas negras perdieron." << endl;
	
	if (jugador1->cantFichas < jugador2->cantFichas)
		s << " -> Fichas blancas perdieron." << endl;

	if (jugador1->cantFichas > jugador2->cantFichas)
		s << " -> Fichas negras perdieron." << endl;

	if (jugador1->cantFichas == jugador2->cantFichas)
	{
		if (jugador1->cantReinas < jugador2->cantReinas)
			s << " -> Fichas blancas perdieron." << endl;

		if (jugador1->cantReinas > jugador2->cantReinas)
			s << " -> Fichas negras perdieron." << endl;

		if (jugador1->cantReinas == jugador2->cantReinas)
			s << " -> Empate." << endl;
	}

	return s.str();
}


