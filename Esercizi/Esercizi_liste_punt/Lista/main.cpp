#include <iostream>
using namespace std;

struct lista
{
    int val;
    lista *next;
};

int length = 50;
typedef lista *p_lista;

p_lista init_lista()
{
    int i;
    p_lista p = new lista;
    p_lista head = p;

    for (i = 0; i < length-1; i++)
    {
        p_lista tmp = new lista;
        p->val = i;
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

p_lista add_head(p_lista head, int val)
{
    p_lista tmp = new lista;
    tmp->val = val;
    tmp->next = head;
    length++;
    return(tmp);
}

void add_middle(p_lista head, int count, int val)
{
    int c = 0;
    p_lista p = head, prec = head;

    while (c != count)
    {
        prec = p;
        p = p->next;
        c++;
    }
    
    p_lista tmp = new lista;
    tmp->val = val;
    tmp->next = p;
    prec->next = tmp;
    length++;
    
}

void add_last(p_lista head, int val)
{
    while (head->next != NULL) head = head->next;

    p_lista tmp = new lista;
    tmp->val = val;
    tmp->next = NULL;
    head->next = tmp;
    length++;
}

p_lista add_elem(p_lista head, int pos, int val)
{
    if(pos == 0)
        head = add_head(head, val);
    else if(pos < length)
        add_middle(head, pos, val);
    else if (pos == length)
        add_last(head, val);
    else
        cout << "Errore: posizione non valida";
    
    return(head);
}   

int main()
{
    p_lista head1 = init_lista();
    stampa_lista(head1);

    int pos, val;
    cout << "Inserire la posizione da sostituire e poi il valore (0 per aggiungere in testa e " << length << " per la coda):\n";
    cin >> pos;
    cin >> val;
    
    head1 = add_elem(head1, pos, val);
    stampa_lista(head1);

    return(0);
}