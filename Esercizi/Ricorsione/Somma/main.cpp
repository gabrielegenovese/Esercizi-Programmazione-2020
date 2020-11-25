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
        p->val = rand()%10;
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

// somma ricorsiva di elementi nella lista
int somma_val(p_lista head)
{
    if (head == NULL) return 0;
    else return (head->val + somma_val(head->next));
}

int main()
{
    srand(time(NULL));
    p_lista head1 = init_lista();
    stampa_lista(head1);

    cout << somma_val(head1) << endl;

    return(0);
}