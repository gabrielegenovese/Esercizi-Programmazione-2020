/*
Definire le strutture dati necessarie per rappresentare una lista della spesa. Ogni elemento della lista è composto dal nome del
prodotto, la quantità da acquistare e dal prezzo unitario, inizialmente impostato a zero. Definire le seguenti funzioni:
1. Una funzione che aggiunge un nuovo articolo da acquistare nella lista, inserendolo in ordine alfabetico (dovrà prendere in input
il nome dell'articolo e la quantità necessaria);
2. Una funzione che prende in input il nome dell'articolo acquistato e il suo prezzo unitario, aggiornandone il prezzo presente nella
lista;
3. Una funzione che restituisce la spesa totale degli articoli acquistati. 
*/

#include <iostream>
#include <cstring>
using namespace std;

struct lista
{
    char prodotto[20];
    int quant;
    double prezzo_unit = 0;
    lista * next;
};

typedef lista * p_lista;

bool ordineAlfabetico(char A[], char B[])
{
    int i = 0;
    while (A[i] == B[i]) i++;
    
    if (A[i] < B[i])
        return true;
    else
        return false;
}

p_lista newProdotto(p_lista head, char prodotto[], int quant)
{
    
    p_lista tmp = head, prec = head;
    bool done = false;
    if(head == NULL)
    {
        head = new lista;
        strcpy(head->prodotto, prodotto);
        head->quant = quant;
        head->next = NULL;
        return head;
    }
    else
    {
        while (head != NULL && !done)
        {
            if(ordineAlfabetico(prodotto, head->prodotto))
            {
                done = true;
                if(prec == tmp)
                {
                    head = new lista;
                    head->next = prec;
                    tmp = head;
                }
                else
                {
                    prec->next = new lista;
                    prec->next->next = head;
                }
            }
            else
            {
                prec = head;
                head = head->next;
            }
        }
    }
    if(!done)
    {
        head = new lista;
        prec->next = head;
        head->next = NULL;
    }
    strcpy(head->prodotto, prodotto);
    head->quant = quant;
    return tmp;
}

void setPrezzo(p_lista head, char prodotto[], double prezzo)
{
    while (head != NULL && strcmp(head->prodotto, prodotto) != 0)
        head = head->next;
    
    if (head != NULL)
        head->prezzo_unit = prezzo;
}

double getSpesa(p_lista head)
{
    if (head == NULL) return 0;
    return head->prezzo_unit*head->quant +(getSpesa(head->next));
}

void stampa_lista(p_lista head)
{
    cout << "Lista:\n";
    while (head != NULL)
    {
        cout << head->prodotto << '\t';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int quant;
    char c[20];
    cin >> c;
    cin >> quant;

    p_lista head = NULL;
    head = newProdotto(head, c, quant);
    setPrezzo(head, c, 2);
    p_lista tmp = head;
    stampa_lista(tmp);
    head = newProdotto(head, (char *)"mango", quant);
    setPrezzo(head, (char *)"mango", 1);
    head = newProdotto(head, (char *)"fico", quant);
    setPrezzo(head, (char *)"fico", 3);
    head = newProdotto(head, (char *)"panana", quant);
    setPrezzo(head, (char *)"panana", 7);
    tmp = head;
    stampa_lista(head);
    cout << getSpesa(head) << endl;
    return(0);
}