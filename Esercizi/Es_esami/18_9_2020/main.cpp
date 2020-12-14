/*
Si consideri un sistema per la gestione delle opere d’arte esposte presso un Museo.
Un Museo `e caratterizzato da un nome e dalla lista di opere d’arte che ospita.
Una opera d’arte `e caratterizzata da un codice univoco, un nome, un autore, l’anno
in cui `e stata realizzata e il numero della stanza in cui `e esposta.
Per semplicit`a si assuma che il Museo oggetto di questo esame ha tre stanze
e ciascuna stanza pu`o accogliere un numero variabile di opere.
Implementare la classe Museo, che prevede i seguenti metodi:
• aggiungi opera, il quale aggiunge una opera d’arte alla lista di quel Museo.
Il metodo deve controllare che l’opera non sia gi`a presente.
Si consideri il caso di un Museo a pagamento. Ciascuna stanza del Museo potr`a
essere visitata pagando un biglietto. Il prezzo del biglietto dipende dalle opere
che vi sono esposte.
• Modificare il metodo aggiungi opera in modo tale da aggiornare il prezzo
del biglietto per la stanza in cui `e esposta quella opera.
• Implementare il metodo stampa prezzo stanze, che visualizza il 
prezzo del biglietto per ciascuna stanza nel museo.
*/

#include <iostream>
#include <cstring>
using namespace std;

struct opera
{
    int codice;
    char nome[20];
    char autore[20];
    int anno;
    int n_stanza;
    opera * next;
};

typedef opera * p_lista;

class Museo
{
    protected:
        char nome[20];
        p_lista head;
    public:
        void newOpera(int codice, char nome[20], char autore[20], int anno, int n_stanza)
        {
            p_lista tmp = this->head;
            if(n_stanza > 0 && n_stanza < 3)
            {
                if (tmp == NULL)
                {
                    tmp = new opera;
                    tmp->codice = codice;
                    strcpy(tmp->nome, nome);
                    strcpy(tmp->autore, autore);
                    tmp->anno = anno;
                    tmp->n_stanza = n_stanza;
                    tmp->next = NULL;
                }
                else
                {
                    bool exist = false;
                    while(tmp->next != NULL)
                    {
                        if(strcmp(tmp->nome, nome) == 0) exist = true;
                        tmp = tmp->next;
                    }
                    
                    if(!exist)
                    {
                        tmp->next = new opera;
                        tmp = tmp->next;
                        strcpy(tmp->nome, nome);
                        strcpy(tmp->autore, autore);
                        tmp->anno = anno;
                        tmp->n_stanza = n_stanza;
                        tmp->next = NULL;
                    }
                }
            }
        }
        Museo(char nome[] = (char *)"")
        {
            strcpy(this->nome, nome);
            this->head = NULL;
        }
};

class MuseoPago : public Museo
{
    protected:
        double price[3];
    public:
    void newOpera(int codice, char nome[20], char autore[20], int anno, int n_stanza)
        {
            p_lista tmp = this->head;
            if(n_stanza > 0 && n_stanza < 3)
            {
                if (tmp == NULL)
                {
                    this->head = new opera;
                    this->head->codice = codice;
                    strcpy(this->head->nome, nome);
                    strcpy(this->head->autore, autore);
                    this->head->anno = anno;
                    this->head->n_stanza = n_stanza;
                    this->head->next = NULL;
                    this->price[n_stanza-1] += 1;
                }
                else
                {
                    bool exist = false;
                    while(tmp->next != NULL)
                    {
                        if(strcmp(tmp->nome, nome) == 0) exist = true;
                        tmp = tmp->next;
                    }
                    
                    if(!exist)
                    {
                        tmp->next = new opera;
                        tmp = tmp->next;
                        strcpy(tmp->nome, nome);
                        strcpy(tmp->autore, autore);
                        tmp->anno = anno;
                        tmp->n_stanza = n_stanza;
                        tmp->next = NULL;
                        this->price[n_stanza-1] += 1;
                    }
                }
            }
        }
    void stampaPrice()
    {
        cout << "Prezzo stanza 1: " << price[0] << endl;
        cout << "Prezzo stanza 2: " << price[1] << endl;
        cout << "Prezzo stanza 3: " << price[2] << endl;
    }
    MuseoPago(char nome[] = (char *)"") : Museo(nome)
    {
        this->head = NULL;
        for (int i = 0; i < 3; i++)
            price[i] = 0;
    }
};

int main()
{
    MuseoPago m1((char *)"CiccioPanza");
    m1.newOpera(1,(char *)"a",(char *)"s",2010,1);
    m1.newOpera(1,(char *)"b",(char *)"s",2010,1);
    m1.newOpera(1,(char *)"c",(char *)"s",2010,2);
    m1.newOpera(1,(char *)"d",(char *)"s",2010,2);
    m1.stampaPrice();
    return 0;
}