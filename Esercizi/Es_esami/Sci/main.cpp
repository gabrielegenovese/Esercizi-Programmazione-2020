/*
Un impianto sciistico di risalita `e caratterizzato da un nome e da un costo di utilizzo (espresso in punti).
Definire mediante array il tipo di dato “comprensorio sciistico” che `e un insieme finito di impianti di risalita.
In seguito, definire la classe skipass con i campi opportuni in modo da ammettere due tipi di skipass:
(a) quello “Giornaliero”, che pu`o essere utilizzato nell’arco di una sola giornata e non ha limite sul numero di ingressi;
(b) quello “Ricaricabile”, che all’acquisto ha un determinato numero di punti, che verranno scalati ad ogni accesso agli
impianti e che dipende dal singolo impianto.
La classe skipass ha i seguenti metodi:
(a) un metodo “accesso” che prende in input il nome di un impianto e una data e consente di accedere all’impianto
(decrementando i punti o controllando che lo skipass `e valido); [una data `e un intero di 8 cifre, le prime 4 sono
l’anno, le altre 2 sono i mesi, le ultime due indicano il giorno]
(b) un metodo “ricarica” che prende in input un intero (che indica i punti oppure un giorno) e un booleano (“vero”
significa che si vuole ricaricare con un altro giorno, “falso” significa che si vogliono ricaricare punti).
*/

#include <iostream>
#include <cstring>
using namespace std;

#define gior true
#define ricar false

struct impianto
{
    char nome[20];
    int costo;
};

typedef impianto *p_impianto;

class Skipass
{
    protected:
        bool tipo;
        int punti;
        int data;
        p_impianto comprensorio[3];
    public:
        void accesso(char c[], int data_oggi)
        {
            if(tipo)
            {
                if(this->data != data_oggi)
                    cout << "Errore: ricaricare per il giorno di oggi" << endl;
            }
            else if(!tipo)
            {
                bool found = false;
                for (int i = 0; i < 3; i++)
                {
                    if(strcmp(this->comprensorio[i]->nome, c) == 0)
                    {
                        
                        found = true;
                        if(this->punti - this->comprensorio[i]->costo > 0)
                            this->punti -= this->comprensorio[i]->costo;
                        else
                            cout << "Errore: ricaricare i punti" << endl;
                        cout << "Hai ancora "<< this->punti << " punti" << endl;
                    }
                }
                if(!found) cout << "Errore: impianto sciistico non trovato" << endl;
            }
        }
        void ricarica(int n, bool b)
        {
            if(b)
                this->data = n;
            else
                this->punti += n;
            this->tipo = b;
        }
        Skipass(int tipo, int data, int punti, p_impianto comprensorio[])
        {
            this->tipo = tipo;
            if(tipo) this->data = data;
            else this->data = 0;
            if(!tipo) this->punti = punti;
            else this->punti = 0;
            this->comprensorio[0] = comprensorio[0];
            this->comprensorio[1] = comprensorio[1];
            this->comprensorio[2] = comprensorio[2];
        }
};

int main()
{
    p_impianto comprensorio[3];
    char c[3][20];
    for (int i = 0; i < 3; i++)
    {
        comprensorio[i] = new impianto;
        cin >> c[i];
        strcpy(comprensorio[i]->nome, c[i]);
        comprensorio[i]->costo = i+1;
    }

    Skipass s = Skipass(gior, 15122020, 0, comprensorio);
    s.accesso(c[0], 15122020);
    s.accesso(c[0], 16122020);
    
    return 0;
}