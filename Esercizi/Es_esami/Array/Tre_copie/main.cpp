/*
ESERCIZIO 19/12/2019 Scrivere una funzione “tre copie” che prende un array di interi e ritorna
“vero” se l’array contiene un elemento con almeno tre copie di esso, “falso” altrimenti.
*/

#include <iostream>
using namespace std;

bool f(int a[], const int l)
{
    int count;
    for (int i = 0; i < l; i++)
    {
        count = 0;
        for (int j = 0; j < l; j++)
            if(a[i] == a[j]) count++;
        if(count > 3) return true;
    }
    return false;
}

int main()
{
    int a[] = {1,2,2,5,2,1,2,4,5};
    
    if(f(a,9)){
        cout << "TRUE" << endl;
    }else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}