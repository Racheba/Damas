 #include"Tablero.h"


Tablero::Tablero()
{
	inicio = NULL;
}

Tablero::~Tablero(){}


void Tablero::crearTablero()
{
	Casilla* act = inicio;
	Casilla* ant = act;

	int i = 0;
	int j = 0;

	for (i, j = 0; i, j < 8; i++, j++)
	{
		if (act == NULL)
		{
			Casilla* casilla = new Casilla(NULL, i, j);
			inicio = casilla;
			act = casilla;
			//cout<< "[" <</* act->getDato() <<*/ act->getFila() << "," << act->getColumna() << "]" << endl;
		}
		else
		{
			Casilla* casilla1 = new Casilla(NULL, i, j);
			act->setDownR(casilla1);
			act = casilla1;

			act->setUpL(ant);
			ant = act;

			//cout << string(i*5, '    ') << "[" <</* act->getDato() << */act->getFila() << "," << act->getColumna() << "]" << endl;
		}
	}

	//-------------------------------------- Haciendo diagonales --------------------------------------
	act = inicio->getDownR();
	Casilla* down = act;
	Casilla* up = act;


	while (act->getDownR() != NULL)
	{
		for (int cont = act->getColumna(), x = act->getColumna() - 1, y = 1; y <= act->getColumna(); x--, y++, cont++)
		{
			Casilla* casilla = new Casilla(NULL, cont + 1, x);
			down->setDownL(casilla);
			down = down->getDownL();

			Casilla* casilla1 = new Casilla(NULL, x, cont + 1);
			up->setUpR(casilla1);
			up = up->getUpR();
		}

		act = act->getDownR();
		down = act;
		up = act;

		while (act->getColumna() >= 4 && act->getDownR() != NULL)
		{
			int z = act->getUpL()->getColumna();

			if (act->getColumna() == 5)
				z = 2;

			if (act->getColumna() == 6)
				z = 1;

			for (int cont = act->getColumna(), x = act->getColumna() - 1, y = 1; y <= z; x--, z--, cont++)
			{
				Casilla* casilla = new Casilla(NULL, cont + 1, x);
				down->setDownL(casilla);
				down = casilla;

				Casilla* casilla1 = new Casilla(NULL, x, cont + 1);
				up->setUpR(casilla1);
				up = casilla1;
			}

			act = act->getDownR();
			down = act;
			up = act;
		}
	}

	//--------------------IMPRIMIR----------------------------------
	/*
	act = inicio;
	down = act;
	up = act;

	while (act->getDownR() != NULL)
	{
	cout << act->getColumna() << endl;

	while (down->getDownL() != NULL && up->getUpR() != NULL)
	{
	down = down->getDownL();
	//	cout << "<--" << down->toString() << endl;

	up = up->getUpR();
	//	cout << "-->" << up->toString() << endl;
	}

	act = act->getDownR();
	down = act;
	up = act;
	}

	*/



	//--------------------------------------- Enlazando Casillas diagonales ---------------------------------------
	act = inicio->getDownR();
	down = act;
	up = act;

	while (act->getDownR() != NULL)
	{
		//cout << act->getColumna() << endl;

		while (down->getDownL() != NULL && up->getUpR() != NULL)
		{
			down->getDownL()->setUpR(down);
			down = down->getDownL();

			//cout << "[" << down->getUpR()->getColumna() << "," << down->getUpR()->getFila() << "]" << endl;

			up->getUpR()->setDownL(up);
			up = up->getUpR();

			//cout << "[" << up->getDownL()->getColumna() << "," << up->getDownL()->getFila() << "]" << endl;

		}

		act = act->getDownR();
		down = act;
		up = act;

	}


	// ----------------------------------- Enlazando Casillas de las triangulares de manera diagonal -----------------------------------

	act = inicio->getDownR();
	down = act;
	up = act;

	Casilla* down1 = act->getDownR();
	Casilla* up1 = act->getDownR();

	while (act->getDownR() != NULL)
	{
		if (act->getFila() < 4)
		{
			for (int i = 1; i <= act->getFila(); i++)
			{
				down = down->getDownL();
				down1 = down1->getDownL();
				down->setDownR(down1);
				down1->setUpL(down);

				up = up->getUpR();
				up1 = up1->getUpR();
				up->setDownR(up1);
				up1->setUpL(up);
			}
			act = act->getDownR();
			down = act;
			up = act;
			down1 = act->getDownR();
			up1 = act->getDownR();
		}

		else
		{
			while (down1->getDownL() != NULL && up1->getUpR() != NULL)
			{
				down = down->getDownL();
				down1 = down1->getDownL();
				down->setDownR(down1);
				down1->setUpL(down);

				up = up->getUpR();
				up1 = up1->getUpR();
				up->setDownR(up1);
				up1->setUpL(up);
			}
			act = act->getDownR();
			down = act;
			up = act;
			down1 = act->getDownR();
			up1 = act->getDownR();
		}

	}
}

void Tablero::imprimirTablero()
{
	Ficha* NEGRA = new Ficha(0, false);
	Ficha* BLANCA = new Ficha(1, false);

	//IMPRIMIENDO COORDENADAS DEL TABLERO
	cout << "\t";
	for (int i = 0; i <= 7; i++) //horizontal
	{
		if (i == 0)
			cout << "    " << i;
		else
			cout << "    " << i;
	}

	//vertical
	int contador = 0;

	for (int i = 0; i <= 7; i)
	{
		if (i == 0)
		{
			cout << "\n\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{
					buscarCasilla(i, contador)->setFicha(NEGRA); 
					cout << "[" << buscarCasilla(i, contador)->getFicha()->toString() << "]";
					contador++;
				}
			}
		}
		else
		{
			contador = 0;

			cout << "\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{
					if (buscarCasilla(i, contador)->getFila() <= 2)
					{
						buscarCasilla(i, contador)->setFicha(NEGRA);
						cout << "[" << buscarCasilla(i, contador)->getFicha()->toString() << "]";
						contador++;
					}
					else
					{
						if (buscarCasilla(i, contador)->getFila() >= 5)
						{
							buscarCasilla(i, contador)->setFicha(BLANCA); 
							cout << "[" << buscarCasilla(i, contador)->getFicha()->toString()<< "]";
							contador++;
						}
						else
						{
							cout << "[   ]";
							contador++;
						}

					}
				}
			}
		}
		i++;
	}

}

void Tablero::imprime2()
{
	cout << "\t";
	for (int i = 0; i <= 7; i++) //horizontal
	{
		if (i == 0)
			cout << "    " << i;
		else
			cout << "    " << i;
	}

	//vertical
	int contador = 0;

	for (int i = 0; i <= 7; i)
	{
		if (i == 0)
		{
			cout << "\n\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{

					cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
					contador++;
				}
			}
		}
		else
		{
			contador = 0;

			cout << "\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{
					if (buscarCasilla(i, contador)->getFila() <= 2)
					{

						cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
						contador++;
					}
					else
					{
						if (buscarCasilla(i, contador)->getFila() >= 5)
						{

							cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
							contador++;
						}
						else
						{
							cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
							contador++;
						}

					}
				}
			}
		}
		i++;
	}

}



Casilla* Tablero::buscarCasilla(int fila, int columna)
{
	Casilla* act = inicio;
	Casilla* down = act;
	Casilla* up = act;

	while (act != NULL)
	{
		if (act->getFila() == fila && act->getColumna() == columna)
			return act;

		while (down->getDownL() != NULL && up->getUpR() != NULL)
		{
			down = down->getDownL();
			if (down->getFila() == fila && down->getColumna() == columna)
				return down;

			up = up->getUpR();
			if (up->getFila() == fila && up->getColumna() == columna)
				return up;
		}
		act = act->getDownR();
		up = act;
		down = act;
	}

	return NULL;

}

void Tablero::rellenarTablero()
{

	cout << "\t";
	for (int i = 0; i <= 7; i++) //horizontal
	{
		if (i == 0)
			cout << "    " << i;
		else
			cout << "    " << i;
	}

	//vertical
	int contador = 0;

	for (int i = 0; i <= 7; i)
	{
		if (i == 0)
		{
			cout << "\n\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{
					cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
					contador++;
				}
			}
		}
		else
		{
			contador = 0;

			cout << "\n\t" << i << " ";

			while (contador <= 7)
			{
				if ((i % 2 == 0 && contador % 2 != 0) || (i % 2 != 0 && contador % 2 == 0))
				{
					cout << "[   ]";
					contador++;
				}
				else
				{
					cout << "[ " << buscarCasilla(i, contador)->getFicha()->toString() << " ]";
					contador++;
				}

			}
		}
		i++;
	}

}

bool Tablero::casillaOcupada(int fila, int colum)
{
	if (buscarCasilla(fila, colum)->getFicha())
		return true;
	else
		return false;
}

void Tablero::diagonalesReina(Casilla* casilla)
{


}

Casilla* Tablero::getInicio(){ return inicio; }

void Tablero::deleteFicha(int fila, int column)
{
	buscarCasilla(fila, column)->setFicha(NULL);
}
