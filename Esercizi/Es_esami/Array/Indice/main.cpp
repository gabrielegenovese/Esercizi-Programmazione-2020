/*
Scrivere una funzione che prende in input un array A di interi e ritorna l’indice di
inizio della sequenza di interi non zero piu` lunga. Ad esempio, con input
1,0,0,5,1,3,0,24,12,75,28,0,0,3
ritorna 7.
*/

#include <iostream>
using namespace std;

int f(int a[], const int l)
{
    int max_l = 0, indice = 0;
    int tmp_l = 0, tmp_i = 0;

    for (int i = 0; i < l; i++)
    {
        if(a[i] == 0)
        {
            if(tmp_l > max_l)
            {
                max_l = tmp_l;
                indice = tmp_i;
            }
            tmp_i = i+1;
            tmp_l = 0;
        }
        else
            tmp_l++;
    }
    
    return indice;
}

int main()
{
    int a[] = {1,0,0,5,1,0,3,24,12,75,28,0,0,3};

    cout << f(a,14) << endl;

    return 0;
}