#include <iostream>
using namespace std;

struct l_stud
{
    int val;
    l_stud *next;
};

int length = 10;
typedef l_stud *p_stud;

// verranno inseriti numeri casuali tra 0 e 99;
p_stud init_l_stud()
{
    int i;
    p_stud p = new l_stud;
    p_stud head = p;

    for (i = 0; i < length-1; i++)
    {
        p_stud tmp = new l_stud;
        p->val = rand()%100;
        p->next = tmp;
        p = tmp;
    }
    
    p->val = i;
    p->next = NULL;
    return(head);
}

void stampa_l_stud(p_stud head)
{
    cout << "l_stud:\n";
    while (head != NULL)
    {
        cout << head->val << '\t';
        head = head->next;
    }

    cout << endl;
}

p_stud matr_pari(p_stud head)
{
    p_stud tmp = head, prec;
    if(head != NULL)
    {
        while((head->val % 2 != 0 || head->val % 4 == 0) && head != NULL)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        prec = tmp;
        tmp = tmp->next;
        while (tmp != NULL)
        {
            if(tmp->val %2 != 0 || tmp->val %4 == 0)
            {
                prec->next = tmp->next;
                delete tmp;
                tmp = prec->next;
            }else
            {
                prec = tmp;
                tmp = tmp->next;
            }
        }
    }
    return head;
}

int main()
{
    srand(time(NULL));
    p_stud head = init_l_stud();
    stampa_l_stud(head);
    head = matr_pari(head);
    stampa_l_stud(head);
}