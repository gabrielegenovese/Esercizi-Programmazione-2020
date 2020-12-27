#include <iostream>
#include <cstring>
using namespace std;

struct regalo
{
    char nome[20];
    double prezzo;
    char dest[20];
    regalo * next;
};

typedef regalo * p_regalo;

p_regalo addRegalo(p_regalo head, char nome[], double prezzo, char dest[])
{
    p_regalo tmp = head;
    if(head == NULL)
    {
        head = new regalo;
        strcpy(head->nome, nome);
        head->prezzo = prezzo;
        strcpy(head->dest, dest);
        head->next = NULL;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
    
        tmp->next = new regalo;
        strcpy(tmp->next->nome, nome);
        tmp->next->prezzo = prezzo;
        strcpy(tmp->next->dest, dest);
        tmp->next->next = NULL;
    }
    return head;
}

p_regalo elimRegalo(p_regalo head, char nome[])
{
    p_regalo tmp = head, prec = tmp;
    bool elim = false;
    while (tmp != NULL & !elim)
    {
        if(strcmp(tmp->nome, nome) == 0)
        {
            if(tmp == head)
            {
                head = head->next;
                delete tmp;
                tmp = NULL;
            }
            else
            {
                prec->next = tmp->next;
                delete tmp;
                tmp = NULL;
            }
            elim = true;
        }else
        {
            prec = tmp;
            tmp = tmp->next;
        }
        
    }
    return head;
}

double getCosto(p_regalo head, char dest[])
{
    double sum = 0;
    while (head != NULL)
    {
        if(strcmp(head->dest, dest) == 0)
            sum += head->prezzo;
        head = head->next;
    }
    return sum;
}

int main()
{
    p_regalo head = NULL;

    head = addRegalo(head,(char *)"ciao", 12, (char *)"Geno");
    head = addRegalo(head,(char *)"ciao", 12, (char *)"Geno");
    head = addRegalo(head,(char *)"ciao", 12, (char *)"Geno");
    head = addRegalo(head,(char *)"ciao", 12, (char *)"Geno");
    head = addRegalo(head,(char *)"ciao", 12, (char *)"Geno");
    cout << getCosto(head, (char *)"Geno") << endl;
    head = elimRegalo(head,(char *)"ciao");
    cout << getCosto(head, (char *)"Geno") << endl;
    return 0;
}