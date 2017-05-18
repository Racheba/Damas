#include"Juego.h"

Juego::Juego(){

}
Juego::~Juego(){}


// ------ METODOS DE FICHA ------
bool Juego::moverFichaBlanca(int fila, int colum, int filaD, int columD, Tablero* tabl)
{
	Casilla* casilla = tabl->buscarCasilla(fila, colum);
	Casilla* casillaD = tabl->buscarCasilla(filaD, columD);
	Ficha* blanca = new Ficha(1, false);
	Ficha* reinaBlanca = new Ficha(1, true);

	if (validaMovFichaBlanca(casilla, casillaD, tabl) == true)
	{
		if (validaComerFichaBlanca (casilla, casillaD) == true)
		{
			if (casilla->getFicha()->FichaesReina() == true)
			{
			
				casillaD->setFicha(reinaBlanca);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				
				casillaD->setFicha(blanca);

				casilla->setFicha(NULL);
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
				casillaD->setFicha(reinaBlanca);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				casillaD->setFicha(blanca);
				casilla->setFicha(NULL);
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
	Ficha* negra = new Ficha(0, false);
	Ficha* reinaNegra = new Ficha(0, true);

	if (validaMovFichaNegra(casilla, casillaD, tabl) == true)
	{
		if (validaComerFichaNegra(casilla, casillaD) == true)
		{
			if (casilla->getFicha()->FichaesReina() == true)
			{
				casillaD->setFicha(reinaNegra);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				casillaD->setFicha(negra);
				casilla->setFicha(NULL);
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
				casillaD->setFicha(reinaNegra);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				casillaD->setFicha(negra);
				casilla->setFicha(NULL);
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
		if ( !casilla->getUpR()->getFicha()) {

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
		if (!casilla->getUpL()->getFicha()) {

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
		if (casilla->getUpR()->getFicha()->getColor() == 1)
		{
			casilla->getUpR()->setFicha(NULL);
			return true;
		}
	}

	if (casilla->getUpL() != NULL && casilla->getUpL()->getUpL() == casillaD)
	{
		if (casilla->getUpL()->getFicha()->getColor() == 1)
		{
			casilla->getUpL()->setFicha(NULL);
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
		if (casilla->getDownR()->getFicha()->getColor() == 0)
		{
			casilla->getDownR()->setFicha(NULL);
			return true;
		}
	}

	if (casilla->getDownL() != NULL && casilla->getDownL()->getDownL() == casillaD)
	{
		if (casilla->getDownL()->getFicha()->getColor() == 0)
		{
			casilla->getDownL()->setFicha(NULL);
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
	if (casilla->getFicha()->FichaesReina() && casilla->getFicha()->getColor() == 0) {
		return false;
	}
	else
	{
		if (casillaD->getColumna() > casilla->getColumna())//casilla D se va a mover a la Derecha
		{
			if (casilla->getDownR()->getFicha()->getColor() == 1) {
				tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() - 1)->setFicha(NULL);
				return true;
			}
			//return 0;
		}
		else
			if (casilla->getDownL()->getFicha()->getColor() == 1 ) {
				tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() + 1)->setFicha(NULL);
				return true;
			}
		//return 0;
	}
}

bool Juego::comerFichaNegra(Casilla* casilla, Casilla * casillaD)
{
	if (casilla->getFicha()->getColor() == 1 && casilla->getFicha()->FichaesReina()) {
		return false;
	}
	else
	{
		if (casillaD->getColumna() > casilla->getColumna())//casilla D se va a mover a la Derecha
		{
			if (casilla->getUpR()->getFicha()->getColor() == 0) {
				tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() - 1)->setFicha(NULL);
				return true;
			}
			return false;
		}
		else
			if (casilla->getUpL()->getFicha()->getColor() == 0) {
				tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() + 1)->setFicha(NULL);
				return true;
			}
		return false;
	}
}

void Juego::coronarFicha(Casilla* casilla)
{
	if (casilla->getFila() == 7 || casilla->getFila() == 0)
	{
		if (casilla->getFicha()->getColor() == 1 && !casilla->getFicha()->FichaesReina())
			casilla->getFicha()->setReina(true);

		if (casilla->getFicha()->getColor() == 0 && !casilla->getFicha()->FichaesReina())
			casilla->getFicha()->setReina(true);
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
	if (casilla->getFicha()->getColor() == 1)
	{
		if (casilla->getUpR() != NULL)
		{
			//ver si lo divido.
			if (casilla->getUpR()->getFicha()->getColor() == 0 && !casilla->getUpR()->getUpR()->getFicha())
				return true;
		}
		else
			return false;

		if (casilla->getUpL() != NULL)
		{
			if (casilla->getUpL()->getFicha()->getColor() == 0 && !casilla->getUpL()->getUpL()->getFicha())
				return true;
		}
		else
			return false;

	}

	//si es negra
	if (casilla->getFicha()->getColor() == 0 && !casilla->getFicha()->FichaesReina())
	{
		if (casilla->getDownR() != NULL)
		{
			if (casilla->getUpR()->getFicha()->getColor() == 1 && !casilla->getDownR()->getDownR()->getFicha())
				return true;
		}
		else
			return false;

		if (casilla->getDownL() != NULL)
		{
			if (casilla->getDownL()->getFicha()->getColor() == 1 && !casilla->getDownL()->getDownL()->getFicha())
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
