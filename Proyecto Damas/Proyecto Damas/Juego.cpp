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
					//comerReina
				casillaD->setFicha(reinaBlanca);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				comerFichaNegra(casilla, casillaD);
				casilla->setFicha(NULL);
				casillaD->setFicha(blanca);

				
				return true;
			}
		}
		else
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
				//comerReina
				casillaD->setFicha(reinaNegra);
				casilla->setFicha(NULL);
				return true;
			}
			else
			{
				comerFichaBlanca(casilla, casillaD);		
				casilla->setFicha(NULL);
				casillaD->setFicha(negra);
		
				return true;
			}
		}
		else
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
	}
	return false;
}

//------ VALIDA FICHA -------- 

bool Juego::validaMovFichaBlanca(Casilla* casilla, Casilla* casillaD, Tablero* tab)
{

	if (casillaD->getFicha() == NULL)
	{
		if (casilla->getUpR() == casillaD || casilla->getUpL() == casillaD)
			return true;

		if (validaComerFichaBlanca(casilla, casillaD) == true)
		{
			if (casillaD->getDownL()->getDownL() == casilla || casillaD->getDownR()->getDownR() == casilla)
				return true;
			else return false; // si no se cumple, la casillaD esta lejos. 

			return true;
		}
		return false;
	}
	return false;

}

bool Juego::validaMovFichaNegra(Casilla* casilla, Casilla* casillaD, Tablero* tab)
{
	if (!casillaD->getFicha())
	{
		if (casilla->getDownR() == casillaD || casilla->getDownL() == casillaD)
			return true;

		if (validaComerFichaNegra(casilla, casillaD) == true)
		{
			if (casillaD->getUpL()->getUpL() == casilla || casillaD->getUpR()->getUpR() == casilla)
				return true;
			else return false; // si no se cumple, la casillaD esta lejos. 

			return true;
		}
		return false;
	}
	return false;






	/*



	if (!casillaD->getFicha())
	{
		if (casilla->getDownL() == casillaD)
		if (casillaD->getColumna() > casilla->getColumna())//derecha
		{
			if (!casilla->getDownR()->getFicha()) {

				if (tab->casillaOcupada(casillaD->getFila(), casillaD->getColumna()) != true)
				{
					//si la ficha es reina //metodo mover a reina
					if (casilla->getFicha()->FichaesReina() == true)
					{
						return true; //revisar que este en sus diagonales
					}

					if (casilla->getDownR() == casillaD || casilla->getDownL() == casillaD)
						return true;
					else
						return false; //cout<<no se puede mover a esa casilla
				}
				else
					return false;

			}

			return true;
		}
		else
			if (!casilla->getDownL()->getFicha())
			{

				if (tab->casillaOcupada(casillaD->getFila(), casillaD->getColumna()) != true)
				{
					//si la ficha es reina //metodo mover a reina
					if (casilla->getFicha()->FichaesReina() == true)
					{
						return true; //revisar que este en sus diagonales
					}

					if (casilla->getDownR() == casillaD || casilla->getDownL() == casillaD)
						return true;
					else
						return false; //cout<<no se puede mover a esa casilla
				}
			}
	}
	return false;*/
}

bool Juego::validaComerFichaBlanca(Casilla* casilla, Casilla* casillaD)
{ //ficha blanca come

	//comer varias veces, ficha normal 
	//lista para guardar el camino
	//si la fila es menor, va a la derecha, si es mayor a la izq.
	//va caminando de Casilla en Casilla, solo si es ficha enemiga, si es amiga no se posa encima.
	//metodo recursivo, cuando se mueve a un Casilla, se vuelve a llamar pero con el Casilla actual.


	











	//si es reina
	/*
	if (casilla->getFicha()->FichaesReina() == true)
	{

	}*/

	//si es en diagonal
	if (casilla->getUpR() != NULL && casilla->getUpR()->getUpR() == casillaD && !casilla->getUpR()->getUpR()->getFicha())
	{
		if (casilla->getUpR()->getFicha()->getColor() == 0)
		{
			//casilla->getUpR()->setFicha(NULL);
			return true;
		}
		return false;
	}

	if (casilla->getUpL() != NULL && casilla->getUpL()->getUpL() == casillaD && !casilla->getUpL()->getUpL()->getFicha())
	{
		if (casilla->getUpL()->getFicha()->getColor() == 0)
		{
			//casilla->getUpL()->setFicha(NULL);
			return true;
		}
		return false;
	}
	return false;
	// si esta lejos...

}

bool Juego::validaComerFichaNegra(Casilla* casilla, Casilla* casillaD)
{//ficha negra come

	//si es reina
	if (casilla->getFicha()->FichaesReina() == true)
	{

	}

	//si es en diagonal
	if (casilla->getDownR() != NULL && casilla->getDownR()->getDownR() == casillaD && !casilla->getDownR()->getDownR()->getFicha())
	{
		if (casilla->getDownR()->getFicha()->getColor() == 1)
		{
			return true;
		}
		return false;
	}


	if (casilla->getDownL() != NULL && casilla->getDownL()->getDownL() == casillaD && !casilla->getDownL()->getDownL()->getFicha())
	{
		if (casilla->getDownL()->getFicha()->getColor() == 1)
		{
			return true;
		}
		return false;
	}
	return false;



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
} //solo la reina come varias

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
				/*tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() - 1)->setFicha(NULL);*/  casilla->getDownR()->setFicha(NULL);
				return true;
			}
			//return 0;
		}
		else
			if (casilla->getDownL()->getFicha()->getColor() == 1 ) {
		/*		tablero->buscarCasilla(casillaD->getFila() - 1, casillaD->getColumna() + 1)->setFicha(NULL); */  casilla->getDownL()->setFicha(NULL);
				return true;
			}
		//return 0;
	}
}

bool Juego::comerFichaNegra(Casilla* casilla, Casilla * casillaD)
{
	if (casilla->getFicha()->getColor() == 1 && casilla->getFicha()->FichaesReina())
	{
		return false;
	}
	else
	{
		if (casillaD->getColumna() > casilla->getColumna())//casilla D se va a mover a la Derecha
		{
			if (casilla->getUpR()->getFicha()->getColor() == 0) {
				/*	tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() - 1)->setFicha(NULL);*/ casilla->getUpR()-> setFicha(NULL);
				return true;
			}
			return false;
		}
		else
			if (casilla->getUpL()->getFicha()->getColor() == 0) {
	/*			tablero->buscarCasilla(casillaD->getFila() + 1, casillaD->getColumna() + 1)->setFicha(NULL); */casilla->getUpL()->setFicha(NULL);
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

bool Juego::debeComer(Casilla* casilla, Casilla* casillaD)
{
	//primero revisar si es reina
/*	if (casilla->getFicha()->FichaesReina() == true)
	{
		return true; //revisar las diagonales de esa casilla. 
	}*/











	//---------  SI ES BLANCA  --------------
	if (casilla->getFicha()->getColor() == 1)
	{
		if (casilla->getUpR()->getFicha())
		{
			if (casilla->getUpR()->getUpR()->getFicha() == NULL)
			{
				if (casilla->getUpR()->getFicha()->getColor() == 0)
				{
					if (casilla->getUpR()->getUpR() != casillaD)
						return true;
					else
						return false;
				}
			}
			
		}
	
	}
	

	//------------------------------------------
	if (casilla->getFicha()->getColor() == 1)
	{
		if (casilla->getUpL()->getFicha())
		{
			if (casilla->getUpL()->getUpL()->getFicha() == NULL)
			{
				if (casilla->getUpL()->getFicha()->getColor() == 0)
				{
					if (casilla->getUpL()->getUpL() != casillaD)
						return true;
					else
						return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}


	//---------  SI ES NEGRA  --------------
	if (casilla->getFicha()->getColor() == 0)
	{
		if (casilla->getDownR()->getFicha())
		{
			if (casilla->getDownR()->getDownR()->getFicha() == NULL)
			{
				if (casilla->getDownR()->getFicha()->getColor() == 1)
				{
					if (casilla->getDownR()->getDownR() != casillaD)
						return true;
					else
						return false;
				}
			}
		}
	}

	//------------------------------------------
	if (casilla->getFicha()->getColor() == 1)
	{
		if (casilla->getDownL()->getFicha())
		{
			if (casilla->getDownL()->getDownL()->getFicha() == NULL)
			{
				if (casilla->getDownL()->getFicha()->getColor() == 0)
				{
					if (casilla->getDownL()->getDownL() != casillaD)
						return true;
					else
						return false;
				}
					
			}
			else
				return false;
		}
		else return false;
	}



} //falta comer para reina.



Tablero* Juego::getTablero(){
	return tablero;
}

void Juego::crear_Tablero()
{
	tablero->crearTablero();
}
