/*
Un punto di ritiro spedizioni pu`o ricevere un qualunque numero di pacchi. Ogni pacco `e contraddistinto da un numero
di ordine e una dimensione (entrambi sono rappresen- tatati da un intero, la dimensione indica il volume).
(a) Definire la classe PuntoRitiro con i campi opportuni e con i metodi aggiungi che aggiunge un pacco al punto di ritiro
(controllando che non ci siano due pacchi con lo stesso numero d’ordine) e rimuovi che rimuove un pacco in base al numero d’ordine.
(b) Definire la sottoclasse Locker che `e un punto di ritiro con un numero fissato di box. Ogni box pu`o contenere un
solo pacco e i box di un Locker possono contenere pacchi fino a una certa dimensione massima.
i. Definire il costruttore Locker che determina il numero dei box e le dimensione massima dei pacchi che possono contenere.
ii. Riscrivere i metodi aggiungi e rimuovi. Il metodo aggiungi stampa errore se il Locker `e pieno oppure quando
la dimensione del pacco `e troppo grande.
*/

#include <iostream>
using namespace std;

struct pacco
{
    int n_ordine;
    int dimensione;
    pacco * next;
};

typedef pacco * p_pacco;

class PuntoRitiro
{
    protected:
        p_pacco head;
    public:
        void addPacco(int n_ordine, int dimenzione)
        {
            if(this->head == NULL)
            {
                this->head = new pacco;
                this->head->n_ordine = n_ordine;
                this->head->dimensione = dimenzione;
                this->head->next = NULL;
            }
            else
            {
                p_pacco tmp = this->head;
                bool doppio = false;
                while (tmp->next != NULL)
                {
                    tmp = tmp->next;
                    if(tmp->n_ordine == n_ordine) doppio = true;
                }

                if(!doppio && tmp->n_ordine != n_ordine)
                {
                    tmp->next = new pacco;
                    tmp->next->n_ordine = n_ordine;
                    tmp->next->dimensione = dimenzione;
                    tmp->next->next = NULL;
                }
            }
        }
        void removePacco(int n_ordine)
        {
            p_pacco tmp = this->head, prec = this->head;
            bool elim = false;
            if(this->head->n_ordine == n_ordine)
            {
                tmp = tmp->next;
                delete(this->head);
                this->head = tmp;
            }
            else
            {
                while(tmp != NULL && !elim)
                {
                    if(tmp->n_ordine == n_ordine)
                    {
                        elim = true;
                        prec->next = tmp->next;
                        delete tmp;
                        tmp = NULL;
                    }else
                    {
                        prec = tmp;
                        tmp = tmp->next;
                    }
                }
            }
        }
        PuntoRitiro()
        {
            head = NULL;
        }
};

class Locker : public PuntoRitiro
{
    protected:
        int n_box;
        int dim_max;
        int cursor;
    public:
        void addPacco(int n_ordine, int dimenzione)
        {
            if(this->head == NULL)
            {
                this->head = new pacco;
                this->head->n_ordine = n_ordine;
                this->head->dimensione = dimenzione;
                this->head->next = NULL;
                this->cursor++;
            }
            else
            {
                p_pacco tmp = this->head;
                bool doppio = false;
                while (tmp->next != NULL)
                {
                    if(tmp->n_ordine == n_ordine) doppio = true;
                    tmp = tmp->next;
                }

                if(!doppio && tmp->n_ordine != n_ordine)
                {
                    if(this->cursor+1 < this->n_box && dimenzione < this->dim_max)
                    {
                        tmp->next = new pacco;
                        tmp->next->n_ordine = n_ordine;
                        tmp->next->dimensione = dimenzione;
                        tmp->next->next = NULL;
                        this->cursor++;
                    }
                    else
                        this->stampaErrore(n_ordine, dimenzione);
                }
                else
                    this->stampaErrore(n_ordine, dimenzione);
            }
        }
        void removePacco(int n_ordine)
        {
            p_pacco tmp = this->head, prec = tmp = this->head;
            bool elim = false;
            if(this->head->n_ordine == n_ordine)
            {
                tmp = tmp->next;
                delete(this->head);
                this->head = tmp;
                this->cursor--;
            }
            else
            {
                while(tmp != NULL && !elim)
                {
                    if(tmp->n_ordine == n_ordine)
                    {
                        elim = true;
                        prec->next = tmp->next;
                        delete tmp;
                        tmp = NULL;
                        this->cursor--;
                    }else
                    {
                        prec = tmp;
                        tmp = tmp->next;
                    }
                }
            }
        }
        void stampaErrore(int n_ordine, int dimenzione)
        {
            cout << "Locker pieno o dimentisioni del pacco troppo gradi\nPacco n "<< n_ordine << " di dimensioni "<< dimenzione << endl;
        }
        Locker(int n_box = 10, int dim_max = 10)
        {
            this->n_box = n_box;
            this->dim_max = dim_max;
            this->cursor = 0;
        }
};


int main()
{

    Locker l = Locker(10);
    l.addPacco(1,2);
    l.addPacco(2,2);
    l.addPacco(3,2);
    l.addPacco(4,2);
    l.addPacco(5,2);
    l.addPacco(6,2);
    l.addPacco(1,2);
    return 0;
}