/*
Definire una classe rainMeter, che calcola la quantità media di pioggia (in
millimetri al giorno) che cade in un certo punto in un dato periodo di tempo.
Definire un opportuno costruttore e i seguenti metodi:
▸ Un metodo void reset() che segnala l’inizio di un nuovo periodo di tempo;
▸ Un metodo void dayEnd() che viene invocato ogni notte a mezzanotte,
segnalando che la durata del periodo di tempo corrente aumenta ogni
giorno;
▸ Un metodo void rain(int n) che viene invocato per comunicare la
caduta di n millimetri di pioggia addizionali nel giorno corrente;
▸ Un metodo double average() che restituisce la quantità media di pioggia
caduta nel periodo corrente. 
*/

#include <iostream>
using namespace std;

class RainMeter
{
    protected:
        int giorni;
        int mm_pioggia;
    public:
        void reset(){ this->giorni = 1; this->mm_pioggia = 0; }

        void dayEnd(){ this->giorni++; }

        void rain(int n){ this->mm_pioggia += n; }

        double avarage(){ return (mm_pioggia/giorni); }

        RainMeter(int giorni = 1, int mm_pioggia = 0)
        {
            this->giorni = giorni;
            this->mm_pioggia = mm_pioggia;
        }
};

int main()
{

}
