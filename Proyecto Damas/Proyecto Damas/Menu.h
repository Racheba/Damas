#include"Juego.h"

class Menu
{
private:
	Juego* juego;
	Tablero* tbl;

public:
	Menu();
	~Menu();

	void MenuPrincipal();
	void MenuJuego();
	void Instrucciones();
};