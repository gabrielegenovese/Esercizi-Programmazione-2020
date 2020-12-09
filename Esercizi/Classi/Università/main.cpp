#include <iostream>
#include <string.h>
using namespace std;

struct corso
{
    char nome[20];
    char docente[20];
    char laurea[20];
    int crediti;
    corso *next;
};

typedef corso * p_corso;

int crediti_tot_prof(p_corso head, char nome[])
{
    int tot = 0;
    while(head != NULL)
    {
        if(strcmp(head->docente, nome) == 0)
            tot += head->crediti;
        head = head->next;
    }
    return tot;
}

int main()
{
    p_corso p1 = new corso;
    p1->crediti=12;
    strcpy(p1->docente, (char *)"Cosimo");
    cout << crediti_tot_prof(p1,(char *)"Cosimo") << endl;

}