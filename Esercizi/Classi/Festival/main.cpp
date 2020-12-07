#include <iostream>
#include <cstring>
using namespace std;

struct l_ospiti
{
    char nome[10];
    double costo;
    int minuti_performance;
    l_ospiti *next;
};

typedef l_ospiti *p_ospiti;

class Ospiti_Festival
{
    protected:
        int n_ospiti;
        p_ospiti ospite;
    public:
        void newOspite(p_ospiti x)
        {
            p_ospiti tmp = this->ospite;
            if(tmp == NULL)
            {
                this->ospite = new l_ospiti;
                this->ospite = x;
            }
            else
            {
                while(tmp->next != NULL)
                    tmp = tmp->next;
                tmp->next = new l_ospiti;
                tmp->next = x;
            }
            this->n_ospiti++;
        }
        void ospiteCostoso()
        {
            p_ospiti tmp = this->ospite, ospiteCost = this->ospite;
            while (tmp != NULL)
            {
                if(tmp->costo > ospiteCost->costo)
                    ospiteCost = tmp;
                tmp = tmp->next;
            }
            cout << "L'ospite più costoso è " << ospiteCost->nome << " con " << ospiteCost->costo << endl;
        }
        Ospiti_Festival(int n_ospiti = 0, p_ospiti ospite = NULL)
        {
            this->n_ospiti = n_ospiti;
            this->ospite = ospite;
        }
};

class Ospiti_FestivalPlus : public Ospiti_Festival
{
    protected:
        double costoTot;
    public:
        double getCostoTot()
        {
            p_ospiti tmp = this->ospite;
            while(tmp != NULL)
            {
                this->costoTot += tmp->costo;
                tmp = tmp->next;
            }
        }
        Ospiti_FestivalPlus(int n_ospiti = 0, p_ospiti ospite = NULL, double costoTot = 0) : Ospiti_Festival(n_ospiti, ospite)
        {
            this->costoTot = costoTot;
        }
};


int main()
{
    Ospiti_Festival lista = Ospiti_Festival();
    p_ospiti osp1 = new l_ospiti;
    strcpy(osp1->nome,"Paolo");
    osp1->costo = 2100;
    osp1->minuti_performance = 10;
    osp1->next = NULL;
    p_ospiti osp2 = new l_ospiti;
    strcpy(osp2->nome,"Gianni");
    osp2->costo = 300;
    osp2->minuti_performance = 120;
    osp2->next = NULL;
    p_ospiti osp3 = new l_ospiti;
    strcpy(osp3->nome,"Giulia");
    osp3->costo = 4300;
    osp3->minuti_performance = 20;
    osp3->next = NULL;

    lista.newOspite(osp1);
    lista.newOspite(osp2);
    lista.newOspite(osp3);
    lista.ospiteCostoso();

    Ospiti_FestivalPlus ospl = Ospiti_FestivalPlus();
    p_ospiti osp4 = new l_ospiti;
    strcpy(osp4->nome,"Giulia");
    osp4->costo = 4300;
    osp4->minuti_performance = 20;
    osp4->next = NULL;
    ospl.newOspite(osp4);
    cout << "costo tot: " << ospl.getCostoTot() << endl;

    return 0;
}