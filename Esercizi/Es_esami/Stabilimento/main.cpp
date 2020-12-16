/*
Definire una classe Stabilimento con un campo che contiene il numero di ombrelloni, un altro il numero di sdraio,
un altro la lista di ospiti. Ogni ospite ha un nome (una stringa di 10 caratteri), un campo numero ombrelloni
affittato e un campo numero sdraio affittato. Definire
1. il costruttore che inizializza ombrelloni e sdraio di uno stabilimento;
2. un metodo insert che inserisce un nuovo ospite (se possibile);
3. un metodo remove che prende il nome dell’ospite e lo rimuove dalla lista (la sua vacanza `e finita).
4. Definire una sottoclasse Stabilimento Plus che ha due ulteriori campi con il costo degli ombrelloni e quello
delle sdraio. Definire
(a) il costruttore;
(b) un metodo che ritorna il guadagno che si ha dagli ospiti attualmente presenti nello stabilimento.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct ospiti
{
    char nome[10];
    int ombrellone;
    int sdraio;
    ospiti * next;
};

typedef ospiti * l_ospiti;

class Stabilimento
{
    protected:
        int n_ombrelloni;
        int n_sdraio;
        l_ospiti head;
    public:
        void insertOspite(char nome[], int ombrellone, int sdraio)
        {
            if(this->n_ombrelloni-ombrellone >= 0 && this->n_sdraio-sdraio >= 0)
            {
                if(this->head == NULL)
                {
                    this->head = new ospiti;
                    strcpy(this->head->nome, nome);
                    this->head->ombrellone = ombrellone;
                    this->head->sdraio = sdraio;
                    this->head->next = NULL;
                }
                else
                {
                    l_ospiti tmp = this->head;
                    while (tmp->next = NULL) tmp = tmp->next;

                    tmp->next = new ospiti;
                    strcpy(tmp->next->nome, nome);
                    tmp->next->ombrellone = ombrellone;
                    tmp->next->sdraio = sdraio;
                    tmp->next->next = NULL;
                }
                this->n_ombrelloni -= ombrellone;
                this->n_sdraio -= sdraio;
            }
            else
            {
                cout << "Siamo pieni" << endl;
            }
            
        }
        void removeOspite(char nome[])
        {
            l_ospiti tmp = this->head, prec = tmp;
            bool elim = false;
            while (tmp != NULL && !elim)
            {
                if(strcmp(tmp->nome, nome) == 0)
                {
                    if(tmp == this->head)
                    {
                        this->n_ombrelloni += this->head->ombrellone;
                        this->n_sdraio += this->head->sdraio;
                        this->head = this->head->next;
                        delete(tmp);
                        tmp = NULL;
                    }
                    else
                    {
                        this->n_ombrelloni += tmp->ombrellone;
                        this->n_sdraio += tmp->sdraio;
                        prec->next = tmp->next;
                        delete(tmp);
                        tmp = NULL;
                    }
                    elim = true;
                }
                else
                {
                    prec = tmp;
                    tmp = tmp->next;
                }
            }
        }
        Stabilimento(int n_ombrelloni, int n_sdraio)
        {
            this->head = NULL;
            this->n_ombrelloni = n_ombrelloni;
            this->n_sdraio = n_sdraio;
        }
};

class StabilimentoPlus : public Stabilimento
{
    protected:
        double costo_ombrellone;
        double costo_sdraio;
    public:
        double getGuadagno()
        {
            l_ospiti tmp = this->head;
            double sum = 0;

            while (tmp != NULL)
            {
                sum += tmp->ombrellone*this->costo_ombrellone + tmp->sdraio*this->costo_sdraio;
                tmp = tmp->next;
            }
            return sum;
        }
        StabilimentoPlus(int n_ombrelloni, int n_sdraio, double costo_ombrellone = 1, double costo_sdraio = 1) : Stabilimento(n_ombrelloni, n_sdraio)
        {
            this->costo_ombrellone = costo_ombrellone;
            this->costo_sdraio = costo_sdraio;
        }
};

int main()
{
    StabilimentoPlus s = StabilimentoPlus(5, 30, 5, 2);
    s.insertOspite((char *)"Ciccio", 1, 2);
    s.insertOspite((char *)"Part", 1, 2);
    s.insertOspite((char *)"Manu", 2, 4);
    s.insertOspite((char *)"nibtrr", 1, 3);
    cout << s.getGuadagno() << endl;
    return 0;
}