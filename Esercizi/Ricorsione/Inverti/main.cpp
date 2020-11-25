#include <iostream>
using namespace std;

struct lista
{
    int val;
    lista *next;
};

int length = 10;
typedef lista *p_lista;

p_lista init_lista()
{
    int i;
    p_lista p = new lista;
    p_lista head = p;

    for (i = 0; i < length-1; i++)
    {
        p_lista tmp = new lista;
        p->val = rand()%100;
        p->next = tmp;
        p = tmp;
    }
    
    p->val = i;
    p->next = NULL;
    return(head);
}

void stampa_lista(p_lista head)
{
    cout << "Lista:\n";
    while (head != NULL)
    {
        cout << head->val << '\t';
        head = head->next;
    }

    cout << endl;
}

/*
Bellissima funzione fatta da Gaiba

Definizione algebrica:

append [] L  = L : []
append (x : l) l1 = x : append l l1

invert [] = []
invert (x : l) = append (invert l) x
*/

p_lista append(p_lista tmp, p_lista p)
{
    if(tmp == NULL) return p;
    else
    {
        tmp->next = append(tmp->next, p);
        return tmp;
    }
    
}

p_lista invert(p_lista head)
{
    if(head == NULL) return NULL;
    else
    {
        p_lista tmp = invert(head->next);
        head->next = NULL;
        return append(tmp, head);
    }
}

/*
Altra verione bella

invertList [] l = l
invertList (x : l) l1 = invertList l1 (x : l1)
*/

p_lista invertList(p_lista curr, p_lista prec)
{
    if (curr != NULL)
    {
        return curr;
    }
    else return prec;
}

int main()
{
    srand(time(NULL));
    p_lista head1 = init_lista();
    stampa_lista(head1);

    head1 = invert(head1);
    stampa_lista(head1);

    return(0);
}