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

bool add_middle(p_lista head, int count, int val)
{
    int c = 0;
    p_lista p = head, prec = head;

    while (c != count && c < length)
    {
        prec = p;
        p = p->next;
        c++;
    }
    
    if (c == length) return(false);
    else{
        p_lista tmp = new lista;
        tmp->val = val;
        tmp->next = p;
        prec->next = tmp;
        length++;
        return(true);
    }
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

int main()
{
    p_lista head1 = init_lista();
    stampa_lista(head1);

    int pos = 4, val = 10;
    if(!add_middle(head1, pos, val))
        cout << "Errore: controllare la posizione selezionata\n(max numero che puoi inserire: " << length-1 << ")\n";
    
    head1 = add_head(head1, 50);
    add_last(head1, 500);
    stampa_lista(head1);

    return(0);
}