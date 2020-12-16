/*
ESERCIZIO 15/6/2020: Scrivere una funzione che prende in input un array A di interi
(l’array non e` ordinato) e ritorna il valore in A che ha piu` copie memorizzate in A.
*/

#include <iostream>
using namespace std;

int f(int a[], const int l)
{
    int max_copie = 0, count, indice;

    for (int i = 0; i < l; i++)
    {
        count = 0;
        
        for (int j = 0; j < l; j++)
            if(a[i] == a[j])
                count++;

        if(count > max_copie)
        {
            max_copie = count;
            indice = i;
        }
    }
    return a[indice];
}

int main()
{
    int a[] = {1,1,2,3,4,5,6,3,3};
    cout << f(a,20) << endl;
    return 0;
}