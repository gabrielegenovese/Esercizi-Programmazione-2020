/*
Esercizio [19/9/2019]
Implementare in C++ il tipo di dato insieme-di-naturali (non si possono utilizzare array).
Quindi implementare le operazioni di unione e intersezione.
*/

#include <iostream>
using namespace std;

struct elemento
{
    int val;
    elemento * next;
};

typedef elemento * insieme;

insieme addElem(int n, insieme a)
{
    insieme tmp = a;
    if (a == NULL)
    {
        a = new elemento;
        a->val = n;
        a->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = new elemento;
        tmp->next->val = n;
        tmp->next->next = NULL;
    }
    
    return a;
}

insieme eliminaduplicati(int n, insieme a)
{
    insieme tmp = a, prec = tmp;
    while(tmp != NULL)
    {
        if(tmp->val == n)
        {
            if(tmp == a)
            {
                a = a->next;
                delete(tmp);
                tmp = NULL;
            }
            else
            {
                prec->next = tmp->next;
                delete(tmp);
                tmp = NULL;
            }
        }
        else
        {
            prec = tmp;
            tmp = tmp->next;
        }
    }
    return a;
}

insieme unione(insieme a, insieme b)
{
    insieme tmp = a;
    while(tmp != NULL)
    {
        b = eliminaduplicati(tmp->val, b);
        tmp = tmp->next;
    }
    tmp = a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = b;
    return a;
}

insieme intersezione(insieme a, insieme b)
{
    insieme tmp = a, c = b;
    insieme ris = NULL, p = ris;
    while (tmp != NULL)
    {
        while (c != NULL)
        {
            if(tmp->val == c->val)
                ris = addElem(tmp->val, ris);

            c = c->next;
            p = ris;
        }
        tmp = tmp->next;
        c = b;
    }
    return ris;
}

void stampa_lista(insieme head)
{
    cout << "Lista:\n";
    while (head != NULL)
    {
        cout << head->val << '\t';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    insieme a = NULL;
    a = addElem(1, a);
    a = addElem(2, a);
    a = addElem(3, a);
    a = addElem(4, a);
    //stampa_lista(a);
    insieme b = NULL;
    b = addElem(4, b);
    b = addElem(5, b);
    b = addElem(6, b);
    b = addElem(1, b);
    a = intersezione(a, b);
    stampa_lista(a);
    return 0;
}