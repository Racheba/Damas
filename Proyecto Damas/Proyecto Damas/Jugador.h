#include"Ficha.h"

class Jugador{
private:
	int cantFichas;
	int cantReinas;
	char tipo;

	int color;

public:
	Jugador(int, char);
	~Jugador();

	int getcantFichas();
	int getColor();
	int getReinas();

	void setCantFichas(int);
	void setColor(int);
	void setReinas(int);

	//SE PIERDE CUANDO...
	bool SinFichas(); //revisar

	string perdio(Jugador*, Jugador*);

	/*if (jugador1->cantFichas <= 4)
		s << "-> Cuenta con " << jugador1->cantFichas << " fichas, desea retirarse?" << endl;

	if (jugador2->cantFichas <= 4)
		s << "-> Cuenta con " << jugador1->cantFichas << " fichas, desea retirarse?" << endl;*/ //EN EL MENU


};