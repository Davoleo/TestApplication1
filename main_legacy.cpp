/*
Author: Davoleo
Date: 24/01/18
Copyright - © - Davoleo - 2018-19
*/

#include <iostream>
#include <string>
#include <cctype>
//#define DEBUG <--- per la debug mode

//#define se if <--- define per la sostituzione

//Frase esempio giusto per aggiugere una riga di codice


int main()
{
    using namespace std;

    //DICHIARAZIONE VARIABILI, MANNAGGIA ALLO SWITCH

    int x = 0, y = 0, z = 0;  //case 1: media
    int media2;
    //double media3 = (x + y + z) / 3; //divisione intera [NO decimali]
    double media4;
    int age = 0;			//case 2: età
    string day = "";		//case 3: lunedì
    double dollari = 0;			//case 4: dollarieuro
    double euro = 0;
    char t = ' ';			//case 5: vocale
    char cUp;


    int scambio;
    cout << "Inserisci il numero della sezione del programma da eseguire: ";
    cin >> scambio;
    switch (scambio)
    {

        case 1:

            //SEZIONE 1: ESERCIZIO MEDIA

            //Data Input [Metodo separato]
            cout << "Inserire il primo numero: ";
            cin >> x;

            cout << "\nInserire il secondo numero ";
            cin >> y;

            cout << "\nInserire il terzo numero ";
            cin >> z;

            //Data Input [Metodo Single Line]
            //cout << "Inserisci 3 numeri interi separati da spazio: ";
            //cin >> a >> b >> c;

            //Processing
            media2 = (x + y + z) / 3; //divisione intera [NO decimali]
            media4 = (x + y + z) / 3.0;	 //divisione DECIMALE


            //Data Output
            cout << "Media 2: " << media2 << endl;
            //cout << "Media 3: " << media3 << endl;
            cout << "Media decimale " << media4 << endl;

            if (x == media2)
            {
                cout << "Il primo numero e' uguale alla media" << endl;
            }
            if (y == media2)
            {
                cout << "Il secondo numero e' uguale alla media" << endl;
            }
            if (z == media2)
            {
                cout << "Il terzo numero e' uguale alla media" << endl;
            }
            if (x != media2)
                if (y != media2)
                    if (z != media2)
                        cout << "I numeri sono diversi dalla media";

            break;

        case 2:
            //SEZIONE 2: ESERCIZIO ETA
            cout << "Inserisci la tua eta': ";
            cin >> age;

            if (age > 0 and age < 120)
            {
                if (age >= 18)
                {
                    cout << "Sei Maggiorenne!" << endl;
                }
                else
                {
                    cout << "Sei Minorenne!" << endl;
                }
            }
            else
            {
                cout << "Eta' non valida!" << endl;
            }





            //SEZIONE 3: LUNEDI
        case 3:
            cout << "Che giorno e'? ";
            cin >> day;
            if (day == "lunedi")
            {
                cout << "Eh lo so... la vita e' una merda :P" << endl;
            }
            else
            {
                cout << "beh dai, ci sono giorni peggiori..." << endl;
            }

            break;

        case 4:
            /*
        cout << "inserisci una somma in dollari ";
        cin >> $;
        cout << "inserisci una somma in euro ";
        cin >> €;
        if ($ > €*1.35)
        {
        cout << $ << " e' maggiore di " << € << endl;
        }
        if ($ = €*1.35)
        {
        cout << $ << " e' uguale a " << € << endl;
        }
        if ($ < €*1.35)
        {
        cout << $ << " e' minore di " << € << endl;
        }
        */

            break;

        case 5:				//CASE 5: VOCALE
            cout << "inserisci una vocale: ";
            cin >> t;
            cUp = toupper(t);

            //char cUp = toupper(t);			dalla libreria cctype / conversione a maiuscolo / se è alfabeto
            if (isalpha(cUp))
                if (cUp== 'A' || cUp == 'E' || cUp == 'I' || cUp == 'O' || cUp == 'U')
                    cout << "questa e' una vocale! :))))))))))))))))" << endl;
                else
                    cout << "questa e' una consonante...  :/" << endl;
            else
                cout << "questo non e' niente, come ti permetti brutto strostro! :'(" << endl ;
            break;

        default:
            cout << "il niente non e' un opzione" << endl;
    }



    //getchar(); richiesta di un carattere
    return 0;


}