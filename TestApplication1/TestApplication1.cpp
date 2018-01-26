// Test1.cpp: definisce il punto di ingresso dell'applicazione console.
/*
Author: D36l
Date: 24/01/18
Version: 1.0
Copyright - © - Davoleo - 2018
*/

/* Catena della programmazione
Codice sorgente/editor > Preprocessore > Compilatore > codice oggetto > linker > loader > codice eseguibile*/

//quando sono presenti le <> significa che è una libreria di default
//quando sono presenti le "" significa che è una libreria customizzata

#include "stdafx.h"
#include <iostream>
#include <limits>
//#define DEBUG <--- per la debug mode

//#define se if <--- define per la sostituzione


int main()
{
	//metodi (Warning) per eliminare l'std all'inizio della linea
	using namespace std;
	//metodo meno rischioso ma meno esteso
	//using std::cout

	//stampa su schermo 
	//std = libreria standard
	//cout = output sulle periferiche
	// il << invia (in questo caso stampa su schermo)

	//cout << "ciao\n";
	//cout << 5;

	//Shift dei numeri binari
	//3 in binario shiftato di 2 posizioni a sinistra

	//3 << 2;
	//cout << (3 << 2) << std::endl;

	//built-in
	//operatori integrali: bool - char - int
	//operatori floating point: float - double

	//lvalue = espressione di sinistra (container)
	//rvalue = espressione di destra (valore)

	//Quanti bit utilizza un certo tipo

	
	
	cout << "Size of short: " << sizeof(short) << " bytes" << endl;
	cout << "Size of int: " << sizeof(int) << " bytes" << endl;
	cout << "Size of long: " << sizeof(long) << " bytes"  << endl;
	cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;

	//unsigned --> per i senza segno

	cout << INT_MAX << endl;
	cout << "Max int con segno" << numeric_limits<int>::max() << endl;
	cout << "Min int con segno" << numeric_limits<int>::min() << endl;
	cout << "Max int senza segno" << numeric_limits<unsigned int>::max() << endl;
	cout << "Max long long senza segno" << numeric_limits<unsigned long long>::max() << endl;

	//input stream = cin
	int euro = 0;
	double cambio = 1;
	cout << "Inserisci il valore in euro: ";
	cin >> euro;
	cout << "Euro letti: " << euro << endl;

	cout << "Fattore di cambio? ";
	cin >> cambio;
	cout << "cambio letto: " << cambio << endl;


	cout << "In moneta cambiata: " << euro * cambio << endl;

#ifdef DEBUG
	cout < "Debug" << "....";
#endif //DEBUG

	//getchar(); richiesta di un carattere
	return 0;
}
