#include <iostream>
using namespace std;

struct lista
{
    int val;
    lista *next;
};

int length = 10;
typedef lista *p_lista;

// verranno inseriti numeri casuali tra 0 e 99;
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

// con lista di appoggio
void print_reverse(p_lista head)
{
    p_lista tmp = new lista;
    tmp->next = NULL;
    tmp->val = head->val;

    while(head->next != NULL)
    {
        head = head->next;
        p_lista rev = new lista;
        rev->next = tmp;
        rev->val = head->val;
        tmp = rev;
    }

    cout << "Stampa al contrario:" << endl;
    stampa_lista(tmp);
}

// senza lista di appoggio
void print_reverse2(p_lista head)
{
    p_lista prec, tmp = head;
    bool ciclo = true;
    int c = 0, cursor = length-1;

    cout << "Print reverse" << endl;
    while (ciclo)
    {
        prec = tmp;
        tmp = tmp->next;
        c++;
        if (c == cursor)
        {
            cout << tmp->val << "\t";
            tmp = head;
            cursor--;
            c = 0;
            if (prec == head)
            {
                cout << prec->val << "\t";
                ciclo = false;
            }
        }
    }
    cout << endl;
}

p_lista add_head(p_lista head, int val)
{
    p_lista tmp = new lista;
    tmp->val = val;
    tmp->next = head;
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
}

void add_last(p_lista head, int val)
{
    while (head->next != NULL) head = head->next;

    p_lista tmp = new lista;
    tmp->val = val;
    tmp->next = NULL;
    head->next = tmp;
}

p_lista add_elem(p_lista head, int pos, int val)
{
    if(pos == 0)
        head = add_head(head, val);
    else if(pos < length && pos > 0)
        add_middle(head, pos, val);
    else if (pos == length)
        add_last(head, val);
    else
        cout << "Errore: posizione non valida\n";
    
    length++;
    return(head);
}   

bool search_elem(p_lista head, int elem)
{
    bool found = false;

    while(head->next != NULL && !found)
    {
        if (head->val == elem) found = true;
        head = head->next;
    }
    return(found);
}

p_lista remove_head(p_lista head)
{
    p_lista tmp = head->next;
    delete head;
    head = tmp;
    return(head);
}

void remove_middle(p_lista head, int pos)
{
    int c = 0;
    while (c < pos-1)
    {
        c++;
        head = head->next;
    }

    p_lista tmp = head->next->next;
    delete head->next;
    head->next = tmp;
}

p_lista remove_elem(p_lista head, int pos)
{
    if(pos == 0)
        head = remove_head(head);
    else if(pos < length && pos > 0)
        remove_middle(head, pos);
    else
        cout << "Errore: posizione non valida\n";
    
    length--;
    return(head);
}

void invert_nodes(p_lista head, int pos1, int pos2)
{
    
}

p_lista elim_multipli(p_lista head, int n)
{
    p_lista tmp = head;
    int pos = 0;
    bool change = true;
    
    while (tmp != NULL)
    {
        if (tmp->val != n && tmp->val != 0)
        {
            if (tmp->val % n == 0)
            {
                //cout << "Eliminato " << tmp->val << endl;
                tmp = tmp->next;
                head = remove_elem(head, pos);
                pos--;
                change = false;
            }
        }
        pos++;
        if(change) tmp = tmp->next;
        change = true;
    }
    return(head);
}

// crivello di Eratostene
p_lista elim_non_primi(p_lista head)
{
    int multipli [] = { 2, 3, 5, 7 };

    for (int i = 0; i < 4; i++)
        head = elim_multipli(head, multipli[i]);
    
    return(head);
}

int main()
{
    // assumo che la mia lista sia inizializzata con valori casuali e lunghezza prestabilita
    srand(time(NULL));
    p_lista head1 = init_lista();
    stampa_lista(head1);

    int pos, val;
    cout << "Inserire la posizione da sostituire (da 0 a " << length-1 << ") " <<
            "e poi il valore (inserire " << length << " per aggiungere in coda):\n";
    cin >> pos;
    cin >> val;

    head1 = add_elem(head1, pos, val);
    stampa_lista(head1);

    cout << "Stampo solo i numeri primi\n";
    head1 = elim_non_primi(head1);
    stampa_lista(head1);

    return(0);
}