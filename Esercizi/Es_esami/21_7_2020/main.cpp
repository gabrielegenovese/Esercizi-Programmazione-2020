/*
Ogni studente della laurea triennale ha un piano di studi, rappresentato da un insieme fisso di corsi (ogni studente deve fare gli stessi esami).
I corsi universitari sono caratterizzati da un codice identificativo (un intero), i crediti formativi (CFU, anche essi interi), e il voto che
lo studente ha preso (rappresentato da un intero maggiore o uguale a 18, che viene posto a 0 se lo studente non ha ancora sostenuto l’esame o non
l’ha superato).
Definire le strutture dati necessarie e la classe PianoStudiTriennale con un costruttore e i seguenti metodi:
1. un metodo esame sostenuto, il quale prende in input il codice del corso e il voto che lo studente ha ottenuto e cambia la votazione finale;
2. un metodo calcola media ponderata, che calcola la media ponderata degli esami sostenuti ed eliminando dal conteggio il voto peggiore.
3. un metodo idoneo laurea che controlla se lo studente pu`o laurearsi (verificando che abbia sostenuto tutti gli esami).
Definire poi una sottoclasse PianoStudiMaster che aggiunge anche il tirocinio al piano di studi dello studente. Il valore del tirocinio `e true se
il tirocinio `e gi`a stato svolto, false altrimenti. Definire il costruttore e i seguenti metodi:
1. il metodo calcola media ponderata (sovrascritto) che calcola la media ponderata degli esami sostenuti senza eliminare il voto peggiore.
2. il metodo idoneo laurea (sovrascritto) che considera anche il tirocinio.
*/

#include <iostream>
using namespace std;

struct corso
{
    int codice;
    int cfu;
    int voto;
};

typedef corso *p_corso;

class PianoStudiTriennale
{
    protected:
        p_corso pianoStudi[5];
    public:
        PianoStudiTriennale(p_corso pianoStudi[])
        {
            //this->pianoStudi = pianoStudi;
        }
};


int main()
{
    
    return(0);
}