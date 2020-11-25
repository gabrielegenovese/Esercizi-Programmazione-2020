/*
Definire le strutture dati necessarie per rappresentare una lista dei libri contenuti in una libreria. Ogni libro ha un titolo, un
prezzo e il numero di copie presenti nel negozio. Definire le seguenti funzioni:
• Una funzione che prende in input il titolo di un libro che un cliente vuole comprare e ne decrementa la quantita (se presente).
Il libro viene rimosso dalla lista se il cliente compra l’ultima copia;
• Una funzione che calcola la media dei prezzi dei libri;
• Una funzione che restituisce il titolo del libro piu` costoso tra quelli presenti nella libreria.
*/

#include <iostream>
using namespace std;

struct lista
{
    int val;
    lista *next;
};

int length = 10;
typedef lista *p_lista;

int main()
{

    return(0);
}