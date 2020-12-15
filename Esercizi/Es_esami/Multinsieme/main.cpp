/*
ESERCIZIO [19/2/2020]
Un multinsieme `e una collezione di oggetti con la loro molteplicit`a. Un semplice multinsieme `e la borsa.
Nella borsa ci sono 10 mele, 3 pere, 1 kiwi. Quindi `e il multinsieme:
borsa = {10 · mela, 3 · pera, 1 · kiwi}
Su un multinsieme `e possibile eseguire le operazioni di add, che aggiunge un elemento al
multinsieme, e remove, che elimina un elemento dal multinsieme. Ad esempio: addmelaborsa = {11·mela,3·pera,1·kiwi}
removekiwiborsa = {10·mela,3·pera}
(a) Definire la classe multinsieme il cui tipo degli elementi che contiene `e int (ad esempio {11 · 0, 328 · −1234}
contiene 11 volte 0 e contiene 328 volte −1234) con i metodi add e remove (Il metodo remove, quando l’elemento non c’`e, non rimuove nulla).
(b) Definire la sotto-classe multinsiemeplus con l’ulteriore metodo addplus che prende in input un elemento e la sua molteplicit`a
e aggiorna il proprio multinsieme aggiungendo quell’elemento con la relativa molteplicit`a. Il metodo addplus deve utilizzare il metodo add della superclasse.
*/

#include <iostream>
using namespace std;

struct elem
{
    int n;
    int num;
    elem * next;
};

typedef elem * p_elem;

class Multinsieme
{
    protected:
        p_elem head;
    public:
        void stampa_lista()
        {
            p_elem tmp = this->head;
            cout << "Multilista:\n";
            while (tmp != NULL)
            {
                cout << "n: "<<tmp->n<<"\t Num: "<<tmp->num<< '\n';
                tmp = tmp->next;
            }
            cout << endl;
        }
        void addElem(int num)
        {
            bool found = false;
            p_elem tmp = this->head;
            if(this->head == NULL)
            {
                this->head = new elem;
                this->head->n = 1;
                this->head->num = num;
                this->head->next = NULL;
            }
            else
            {
                while(tmp->next != NULL && !found)
                {
                    if(tmp->num == num)
                        found = true;
                    else
                        tmp = tmp->next;
                }

                if(tmp->next == NULL && !found && tmp->num != num)
                {
                    tmp->next = new elem;
                    tmp->next->n = 1;
                    tmp->next->num = num;
                    tmp->next->next = NULL;
                }
                else
                    tmp->n++;
            }         
        }
        void removeElem(int num)
        {
            bool found = false;
            p_elem tmp = this->head, prec = this->head;
            if(this->head->num == num)
            {
                this->head->n--;
                if(this->head->n <= 0)
                {
                    tmp = tmp->next;
                    delete(this->head);
                    this->head = tmp;
                }
            }
            else
            {
                while(tmp->next != NULL && !found)
                {
                    if(tmp->num == num)
                        found = true;
                    else
                    {
                        prec = tmp;
                        tmp = tmp->next;
                    }
                }

                if(found || tmp->num == num)
                {
                    tmp->n--;
                    if(tmp->n <= 0)
                    {
                        prec->next = tmp->next;
                        delete(tmp);
                        tmp = NULL;
                    }
                }
            }
        }
        Multinsieme()
        {
            head = NULL;
        }
};

class MultinsiemePlus : public Multinsieme
{
    protected:
    public:
        void addPlus(int n, int num)
        {
            Multinsieme::addElem(num);
            for (int i = 1; i < n; i++)
            {
                Multinsieme::addElem(num);
            }
        }
        MultinsiemePlus() : Multinsieme(){}

};

int main()
{
    Multinsieme m = Multinsieme();
    m.addElem(1);
    m.addElem(2);
    m.addElem(1);
    m.stampa_lista();
    m.removeElem(2);
    m.stampa_lista();
    MultinsiemePlus p = MultinsiemePlus();
    p.addPlus(12, 123);
    p.addPlus(15, 123);
    p.stampa_lista();

    return 0;
}