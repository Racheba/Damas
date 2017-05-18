#include"Tablero.h"
#include"Jugador.h"

class Juego{
private:
	Tablero* tablero;

public:
	Juego();
	~Juego();

	Tablero* getTablero();
	void crear_Tablero();

	bool moverFichaNegra(int fila, int colum, int filaD, int columD, Tablero*);
	bool moverFichaBlanca(int fila, int colum, int filaD, int columD, Tablero*);

	bool comerFichaNegra(Casilla*, Casilla*);
	bool comerFichaBlanca(Casilla*, Casilla*);
	void coronarFicha(Casilla*);
	bool debeComer(Casilla*);

	bool validaMovFichaNegra(Casilla*, Casilla*, Tablero*);
	bool validaMovFichaBlanca(Casilla*, Casilla*, Tablero*);

	bool validaComerFichaBlanca(Casilla*, Casilla*);
	bool validaComerFichaNegra(Casilla*, Casilla*);
	bool validaComerVariasBlancas(Casilla*, Casilla*);
	bool validaComerVariasNegras(Casilla*, Casilla*);


	//BUUUUU2

};