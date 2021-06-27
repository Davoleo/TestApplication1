// Application start point is defined in CMakeLists
/*
Author: Davoleo
Date: 24/01/18
Copyright - © - Davoleo - 2018-19
*/

/* Catena della programmazione
Codice sorgente/editor > Preprocessore > Compilatore > codice oggetto > linker > loader > codice eseguibile*/

//Stile
//1) definizione e inizializzazione strutture dati [variabili]
//2) acquisizione dei dati INDISPENSABILI [INPUT]
//3) elaborazione dei dati [calcoli ecc..] {PROCESSING}
//4) comunicazione dei risultati [OUTPUT]

//quando sono presenti le <> significa che è una libreria di default
//quando sono presenti le "" significa che è una libreria customizzata

#include <iostream>
#include <limits>
#include <string>
//#define DEBUG <--- per la debug mode

//#define se if <--- define per la sostituzione


int run()
{
    //SEZIONE 1: HUB

    //metodi (Warning) per eliminare l'std all'inizio della linea
    //using namespace std;
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

    //Operatori
    // operatore logico  AND: "&&"
    // operatore logico NOT: "!"
    // operatore logico OR: "||"
    // l'operatore AND ha la priorità sull'operatore OR
    // il not fuori dalle parentesi si può togliere, invertendo tutti gli operatori [&& diventa ||]

    using namespace std;

    int tr, fa;
    tr = true;
    fa = false;
    cout << "vero = " << tr << " falso = " << fa << endl;

    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;

    //unsigned --> per i senza segno
    
    cout << "Max int con segno: " << numeric_limits<int>::max() << endl;
    cout << "Min int con segno: " << numeric_limits<int>::min() << endl;
    cout << "Max int senza segno: " << numeric_limits<unsigned int>::max() << endl;
    cout << "Max long long senza segno: " << numeric_limits<unsigned long long>::max() << endl;

    //input stream = cin
    int euro = 0;
    double cambio = 1;

    cout << "Inserisci il valore in euro: ";
    cin >> euro;
    cout << "Euro letti: " << euro << endl;

    //Struttura selettiva IF - ELSE
    if (euro <= 0)
    {
        cout << "Inserisci un numero positivo plz!" << endl;
    }
    else
    {
        cout << "Fattore di cambio? ";
        cin >> cambio;
        if (cambio >= 0)
        {
            cout << "cambio letto: " << cambio << endl;
            cout << "In moneta cambiata: " << euro * cambio << endl;
        }
        else
        {
            cout << "Il cambio non può essere negativo" << endl;
        }
    }

    int escludi_da_anno = 1970, a_anno = 2000, anno = 0;

    cout << "in che anno sei nato? ";
    cin >> anno;

    if   (anno < escludi_da_anno || anno > a_anno)
        cout << "\nVuoi partecipare ad un sondaggio sulle banane azzurre?";

    string s1 = "paperino", s2 = "paperina";

    // (posizione s1, durata s1, var s2, posizione s2, durata s2)
    if (s1.compare(2, 3, s2, 2, 3) == 0) cout << "uguali\n";

    //Addizione tra due input
    int addendo1 = 0, addendo2 = 0;
    cout << "Inserisci il primo addendo: ";
    cin >> addendo1;
    cout << "Inserisci il secondo addendo: ";
    cin >> addendo2;
    cout << "risultato: " << addendo1 + addendo2 << endl;

    //Costanti letterali e numeri sosia

    int sosia1 = 060;		//costante ottale
    int sosia2 = 0x30;		//costante esadecimale
    int sosia3 = 48;		//costante letterale decimale
    int sosia4 = 0b110000;	//costante binaria

    cout << "Sosia 1: " << sosia1 << endl;
    cout << "Sosia 2: " << sosia2 << endl;
    cout << "Sosia 3: " << sosia3 << endl;
    cout << "Sosia 4: " << sosia4 << endl;

    unsigned int us = 40000U;

    /*unsigned long schifoso = 0xF0UL;
    long sentimentale = 0xFEEL;
    cout << schifoso << endl;
    cout << sentimentale << endl;*/


    // Utilizzo Switch

    int i = 0;
    cin >> i;
    switch (i)
    {
        case 1:
            cout << "sono un panda bello" << endl;
            break;
        default: cout << "sei un coglione quella non era un opzione" << endl;
            break;
    }

    //Ciclo For
    for (int u = 0; u < 8; u++)
    {
        cout << "zambo fa shifo a spiegare" << endl;
    }

    //Ciclo While
    int o = 0;
    while (o < 8)
    {
        cout << "banana" << endl;
        o++;
    }

    int l = 0;
    do
    {
        cout << "Hello world" << endl;
        l++;
    }

    while (l < 8);

    //getchar(); richiesta di una carattere
    return 0;
}
