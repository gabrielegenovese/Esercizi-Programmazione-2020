/*
Scrivere una funzione che prende un array di interi e
restituisce il numero massimo di duplicati. Ad esempio,
se l’array in input `e    7 8 9 1 7 0 8
restituisce 2.
*/

#include <iostream>
using namespace std;

int f(int a[], const int l)
{
    int max_c = 0;
    bool b[l];
    int count;
    
    for (int i = 0; i < l; i++)
        b[i] = true;
    
    for (int i = 0; i < l-1; i++)
    {
        count = 1;
        for (int j = i+1; j < l; j++)
        {
            if(a[i] == a[j] && b[j])
            {
                count++;
                b[j] = false;
            }
        }
        
        if(count == 2) max_c++;
    }

    return max_c;
}

int main()
{
    int a[] = {1, 2, 1, 1, 4 , 1, 3, 1, 4, 2 , 3};

    cout << f(a,11) << endl;

    return 0;
}