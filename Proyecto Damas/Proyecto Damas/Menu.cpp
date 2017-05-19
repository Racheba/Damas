#include"Menu.h"
#include <conio.h>
#include <windows.h>

Menu::Menu(){}
Menu::~Menu(){}

void Menu::MenuPrincipal()
{

	int opcion;
	bool bandera = false;

	do{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "\n - - - - - - - - - DAMAS INGLESAS - - - - - - - - - " << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "\n\t\t   1. Jugar" << endl;
		cout << "\n\t\t   2. Intrucciones" << endl;
		cout << "\n\t\t   3. Salir" << endl;

		cout << "\n\n -> Inserte su opcion: ";
		cin >> opcion;

		switch (opcion)
		{

		case 1:
			system("cls");
			MenuJuego();
			system("pause");
			break;

		case 2:
			system("cls");
			Instrucciones();
			break;

		case 3:
			bandera = true;
			break;

		}
	} while (bandera != true);

}

void Menu::MenuJuego()
{
	int fila;
	int columna;
	int filaD;
	int columnaD;
	int turno = 0;
	int salir = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "\n - - - - - - - - - DAMAS INGLESAS - - - - - - - - - " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\n\n" << endl;

	Juego* juego = new Juego();
	Tablero* tablero = new Tablero();
	Jugador* jugador1 = new Jugador(12, 'b');
	Jugador* jugador2 = new Jugador(12, 'n');

	tablero->crearTablero();
	tablero->imprimirTablero();

	cout << "\n\n\n";
	cout << " (Inserte 1 para salir, cualquier tecla para continuar): "; cin >> salir;

	while (salir != 1)
	{
		if (turno % 2 == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n \n \n -> Jugador 1:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
			cout << " \t\t -> Fila:";
			cin >> fila;
			cout << "\t\t -> Columna: ";
			cin >> columna;

			cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
			cout << " \t\t -> Fila:";
			cin >> filaD;
			cout << "\t\t -> Columna: ";
			cin >> columnaD;

			
			while (juego->debeComer(tablero->buscarCasilla(fila, columna)) == true)
			{
				cout << " DEBE COMER" << endl << endl;

				cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
				cout << " \t\t -> Fila:";
				cin >> fila;
				cout << "\t\t -> Columna: ";
				cin >> columna;

				cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
				cout << " \t\t -> Fila:";
				cin >> filaD;
				cout << "\t\t -> Columna: ";
				cin >> columnaD;
			}

			while (juego->moverFichaBlanca(fila, columna, filaD, columnaD, tablero) == false)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "\t\t **** MOVIMIENTO INVALIDO, INTENTE DE NUEVO **** " << endl << endl;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n \n \n -> Jugador 1:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
				cout << " /\t\t -> Fila:";
				cin >> fila;
				cout << "\t\t -> Columna: ";
				cin >> columna;

				cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
				cout << " /\t\t -> Fila:";
				cin >> filaD;
				cout << "\t\t -> Columna: ";
				cin >> columnaD;
			}
			tablero->deleteFicha(fila, columna);
			tablero->imprime2();
			turno++;
			cout << " ** Si desea salir del juego, inserte 1, si no, inserte 0 ** "; cin >> salir;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n \n \n -> Jugador 2:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
			cout << " /\t\t -> Fila:";
			cin >> fila;
			cout << "\t\t -> Columna: ";
			cin >> columna;

			cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
			cout << " /\t\t -> Fila:";
			cin >> filaD;
			cout << "\t\t -> Columna: ";
			cin >> columnaD;

			while (juego->debeComer(tablero->buscarCasilla(fila, columna)) == true)
			{
				cout << " DEBE COMER" << endl << endl;

				cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
				cout << " \t\t -> Fila:";
				cin >> fila;
				cout << "\t\t -> Columna: ";
				cin >> columna;

				cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
				cout << " \t\t -> Fila:";
				cin >> filaD;
				cout << "\t\t -> Columna: ";
				cin >> columnaD;
			}

			while (juego->moverFichaNegra(fila, columna, filaD, columnaD, tablero) == false)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "\t\t **** MOVIMIENTO INVALIDO, INTENTE DE NUEVO **** " << endl << endl;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\n \n \n -> Jugador 2:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << " Inserte la fila y columna donde se encuentra la ficha que desea mover: " << endl;
				cout << " /\t\t -> Fila:";
				cin >> fila;
				cout << "\t\t -> Columna: ";
				cin >> columna;

				cout << "\n Ahora inserte la fila y columna de la casilla destino:" << endl;
				cout << " /\t\t -> Fila:";
				cin >> filaD;
				cout << "\t\t -> Columna: ";
				cin >> columnaD;
			}
			tablero->deleteFicha(fila, columna);
			tablero->imprime2();
			turno++;
			cout << " ** Si desea salir del juego, inserte 1, si no, inserte 0 ** "; cin >> salir;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n \t\t **** LA PARTIDA TERMINO, GRACIAS POR JUGAR ****" << endl;


}

void Menu::Instrucciones()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "\n\n ===============*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << " INSTRUCCIONES ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "*=============== " << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n * Como jugar: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\t      Juego para dos jugadores. Cada jugador contara con 12 fichas, el " << endl;
	cout << " jugador 1 tendra las fichas Blancas y el jugador 2 las Negras." << endl << endl;
	cout << " El juego consiste en mover las fichas de manera diagonal, solo un espacio y     solo hacia adelante, con  la intencion de en algun momento lograr capturar las  fichas del contrincante." << endl;
	cout << " Se juega por turnos, empieza el jugador 1, solo se podra mover una pieza por    turno. " << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n * Comer fichas: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\t        Para comer una ficha, se tendra que saltar por encima de esta,   de  manera diagonal a la siguiente casilla, solo si esta se encuentra vacia." << endl;
	cout << " El jugador podra comer varias fichas en un mismo turno solo si entre estas hay  una casilla desocupada y se encuentra en la diagonal de la misma.";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n\n * Ficha Reina: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\t       Una ficha es reina al llegar al extremo opuesto del tablero,      donde se encuentran inicialmente las fichas del contrincante. Es decir, en la   fila  0 o la 7.";
	cout << " Una vez que es reina, la inicial de su ficha pasara a ser una   mayuscula (N para negras y B para blancas). La reina se puede mover cuantos     espacios desee, ";
	cout << " y hacia adelante y atras. Tambien puede comerse una ficha que  se encuentre lejos, pero en su diagonal, mientras no haya un espacio vacio     despues de esta. " << endl;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n * Objetivo: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\t    El objetivo del juego es lograr capturar todas las fichas del " << endl;
	cout << " oponente, o bien, acorrarlas para que ya no pueda realizar mas movimientos o " << endl;
	cout << " estos lo lleven a su captura. Gana el jugador que tenga menos fichas, o hay     empate cuando no se pueden hacer mas movimientos." << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "\n\n\n\t -> PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL <- " << endl << endl << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");

}
