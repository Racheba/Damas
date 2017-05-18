#include"Casilla.h"
#include<string>

class Tablero{
private:
	Casilla* inicio;

public:
	Tablero();
	~Tablero();

	//JOAN

	void crearTablero();
	void imprimirTablero();
	void imprime2();
	void rellenarTablero();

	//-------------------------------------
	bool casillaOcupada(int, int);
	Casilla* buscarCasilla(int, int);
	void diagonalesReina(Casilla*);
	Casilla* getInicio();

	void deleteFicha(int, int);
	//-------------------------------------
};