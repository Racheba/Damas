#include"Juego.h"

class Menu
{
private:
	Juego* juego;
	Tablero* tbl;

public:
	Menu();
	~Menu();

	void Menu1();
	void MenuPrincipal();
	void MenuJuego();
	void Instrucciones();
};