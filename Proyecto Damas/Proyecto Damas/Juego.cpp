#include"Juego.h"

Juego::Juego(){

}
Juego::~Juego(){}


// ------ METODOS DE FICHA ------
bool Juego::moverFichaBlanca(int fila, int colum, int filaD, int columD, Tablero* tabl)
{
	Casilla* casilla = tabl->buscarCasilla(fila, colum);
	Casilla* casillaD = tabl->buscarCasilla(filaD, columD);

	if (validaMovFichaBlanca(casilla, casillaD, tabl) == true)
	{
		if (validaComerFichaBlanca (casilla, casillaD) == true)
		{
			if (casilla->getFicha()->FichaesReina() == true)
			{
				casillaD->setDato('B');
				casilla->setDato(' ');
				return true;
			}
			else
			{
				casillaD->setDato('b');

				casilla->setDato(' ');
				return true;
			}
		}
		else
		{
			if (debeComer(casilla) == true)
			{
				cout << "Debe comer" << endl;
				return false;
			}

			if (casilla->getFicha()->FichaesReina() == true)
			{
				casillaD->setDato('B');
				casilla->setDato(' ');
				return true;
			}
			else
			{
				casillaD->setDato('b');
				casilla->setDato(' ');
				return true;
			}
		}
	}
	return false;
}

bool Juego::moverFichaNegra(int fila, int colum, int filaD, int columD, Tablero* tabl)
{
	Casilla* casilla = tabl->buscarCasilla(fila, colum);
	Casilla* casillaD = tabl->buscarCasilla(filaD, columD);

	if (validaMovFichaNegra(casilla, casillaD, tabl) == true)
	{
		if (validaComerFichaNegra(casilla, casillaD) == true)
		{
			if (casilla->getFicha()->FichaesReina() == true)
			{
				casillaD->setDato('N');
				casilla->setDato(' ');
				return true;
			}
			else
			{
				casillaD->setDato('n');
				casilla->setDato(' ');
				return true;
			}
		}
		else
		{
			if (debeComer(casilla) == true)
			{
				cout << "Debe comer" << endl;
				return false;
			}

			if (casilla->getFicha()->FichaesReina() == true)
			{
				casillaD->setDato('N');
				casilla->setDato(' ');
				return true;
			}
			else
			{
				casillaD->setDato('n');
				casilla->setDato(' ');
				return true;
			}
		}
	}
	return false;
}

//------ VALIDA FICHA -------- 

bool Juego::validaMovFichaBlanca(Casilla* casilla, Casilla* casillaD, Tablero* tab)
{
	if (casillaD->getColumna() > casilla->getColumna())//derecha
	{
		if (casilla->getUpR()->getDato() == ' ') {

			if (tab->casillaOcupada(casillaD->getFila(), casillaD->getColumna()) != true)
			{
				//si la ficha es reina //metodo mover a reina
				if (casilla->getFicha()->FichaesReina() == true)
				{
					return true; //revisar que este en sus diagonales
				}

				if (casilla->getUpR() == casillaD || casilla->getUpL() == casillaD)
					return true;
				else
					return false; //cout<<no se puede mover a esa casilla
			}
			else
				return false;

		}
		else
			comerFichaNegra(casilla, casillaD);
		return true;
	}
	else
		if (casilla->getUpL()->getDato() == ' ') {

			if (tab->casillaOcupada(casillaD->getFila(), casillaD->getColumna()) != true)
			{
				//si la ficha es reina //metodo mover a reina
				if (casilla->getFicha()->FichaesReina() == true)
				{
					return true; //revisar que este en sus diagonales
				}

				if (casilla->getUpR() == casillaD || casilla->getUpL() == casillaD)
					return true;
				else
					return false; //cout<<no se puede mover a esa casilla

			}
			else
				comerFichaNegra(casilla, casillaD);
			return true;
		}
}



bool Juego::validaMovFichaNegra(Casilla* casilla, Casilla* casillaD, Tablero* tab)
{
	if (tab->casillaOcupada(casillaD->getFila(), casillaD->getColumna()) != true)
	{
		//si la ficha es reina //metodo mover a reina
		if (casilla->getFicha()->FichaesReina() == true)
		{
			return true; //revisar las diagonales de esa casilla. 
		}

		if (casilla->getDownR() == casillaD || casilla->getDownL() == casillaD)
			return true;
		else
			return false; //cout<<no se puede mover a esa casilla
	}
	else
		return false; //casilla ocupada o no existe.
}

bool Juego::validaComerFichaBlanca(Casilla* casilla, Casilla* casillaD)
{ //ficha blanca come

	//comer varias veces, ficha normal 
	//lista para guardar el camino
	//si la fila es menor, va a la derecha, si es mayor a la izq.
	//va caminando de Casilla en Casilla, solo si es ficha enemiga, si es amiga no se posa encima.
	//metodo recursivo, cuando se mueve a un Casilla, se vuelve a llamar pero con el Casilla actual.














	//si es reina
	if (casilla->getFicha()->FichaesReina() == true)
	{

	}

	//si es en diagonal
	if (casilla->getUpR() != NULL && casilla->getUpR()->getUpR() == casillaD)
	{
		if (casilla->getUpR()->getDato() == 'b' || casilla->getUpR()->getDato() == 'B')
		{
			casilla->getUpR()->setDato(' ');
			return true;
		}
	}

	if (casilla->getUpL() != NULL && casilla->getUpL()->getUpL() == casillaD)
	{
		if (casilla->getUpL()->getDato() == 'b' || casilla->getUpL()->getDato() == 'B')
		{
			casilla->getUpL()->setDato(' ');
			return true;
		}
	}

	// si esta lejos...



}

bool Juego::validaComerFichaNegra(Casilla* casilla, Casilla* casillaD)
{//ficha negra come

	//si es reina
	if (casilla->getFicha()->FichaesReina() == true)
	{

	}

	//si es en diagonal
	if (casilla->getDownR() != NULL && casilla->getDownR()->getDownR() == casillaD)
	{
		if (casilla->getDownR()->getDato() == 'n' || casilla->getDownR()->getDato() == 'N')
		{
			casilla->getDownR()->setDato(' ');
			return true;
		}
	}

	if (casilla->getDownL() != NULL && casilla->getDownL()->getDownL() == casillaD)
	{
		if (casilla->getDownL()->getDato() == 'n' || casilla->getDownL()->getDato() == 'N')
		{
			casilla->getDownL()->setDato(' ');
			return true;
		}
	}

	//si esta lejos...


}

bool Juego::validaComerVariasBlancas(Casilla* casilla, Casilla* casillaD)
{
	if (casillaD->getColumna() > casilla->getColumna())
	{
		return true;
	}
}

bool Juego:: validaComerVariasNegras(Casilla* casilla, Casilla* casillaD)
{
	return true;
}

bool Juego::comerFichaBlanca(Casilla* casilla, Casilla* casillaD)
{
	//comer fichas las veces que se diga, agregar un contador.  o un while que llame reiteradas veces a comer ficha. 
	if (casilla->getDato() == 'N') {
		return false;
	}
	else
	{
		if (casillaD->getColumna() > casilla->getColumna())//casilla D se va a mover a la Derecha
		{
			if (casilla->getDownR()->getDato() == 'b' || casilla->getDownR()->getDato() == 'B') {
				tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() - 1)->setDato(' ');
				return true;
			}
			//return 0;
		}
		else
			if (casilla->getDownL()->getDato() == 'b' || casilla->getDownL()->getDato() == 'B') {
				tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() + 1)->setDato(' ');
				return true;
			}
		//return 0;
	}
}

bool Juego::comerFichaNegra(Casilla* casilla, Casilla * casillaD)
{
	if (casilla->getDato() == 'B') {
		return false;
	}
	else
	{
		if (casillaD->getColumna() > casilla->getColumna())//casilla D se va a mover a la Derecha
		{
			if (casilla->getUpR()->getDato() == 'n' || casilla->getUpR()->getDato() == 'N') {
				tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() - 1)->setDato(' ');
				return true;
			}
			return false;
		}
		else
			if (casilla->getUpL()->getDato() == 'n' || casilla->getUpL()->getDato() == 'N') {
				tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() + 1)->setDato(' ');
				return true;
			}
		return false;
	}
}

void Juego::coronarFicha(Casilla* casilla)
{
	if (casilla->getFila() == 7 || casilla->getFila() == 0)
	{
		if (casilla->getDato() == 'b')
			casilla->setDato('B');

		if (casilla->getDato() == 'n')
			casilla->setDato('N');
	}
}

bool Juego::debeComer(Casilla* casilla)
{
	//primero revisar si es reina
	if (casilla->getFicha()->FichaesReina() == true)
	{
		return true; //revisar las diagonales de esa casilla. 
	}

	//si es blanca 
	if (casilla->getDato() == 'b')
	{
		if (casilla->getUpR() != NULL)
		{
			//ver si lo divido.
			if (casilla->getUpR()->getDato() == 'n' && casilla->getUpR()->getUpR()->getDato() == ' ' || casilla->getUpR()->getDato() == 'N'  && casilla->getUpR()->getUpR()->getDato() == ' ')
				return true;
		}
		else
			return false;

		if (casilla->getUpL() != NULL)
		{
			if (casilla->getUpL()->getDato() == 'n' && casilla->getUpL()->getUpL()->getDato() == ' ' || casilla->getUpL()->getDato() == 'N' && casilla->getUpL()->getUpL()->getDato() == ' ')
				return true;
		}
		else
			return false;

	}

	//si es negra
	if (casilla->getDato() == 'n')
	{
		if (casilla->getDownR() != NULL)
		{
			if (casilla->getUpR()->getDato() == 'b' && casilla->getDownR()->getDownR()->getDato() == ' ' || casilla->getUpR()->getDato() == 'B' && casilla->getDownR()->getDownR()->getDato() == ' ')
				return true;
		}
		else
			return false;

		if (casilla->getDownL() != NULL)
		{
			if (casilla->getDownL()->getDato() == 'b' && casilla->getDownL()->getDownL()->getDato() == ' ' || casilla->getDownL()->getDato() == 'B' && casilla->getDownL()->getDownL()->getDato() == ' ')
				return true;
		}
		else
			return false;
	}


} //falta comer para reina.



Tablero* Juego::getTablero(){
	return tablero;
}

void Juego::crear_Tablero()
{
	tablero->crearTablero();
}
