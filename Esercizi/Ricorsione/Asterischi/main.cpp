#include <iostream>
using namespace std;

// scrivere una funzione ricorsiva che prende n e stampa un numero di
// asterischi uguale alla somma dei quadrati dei primi n-numeri naturali

void stampa_asterischi(int cicli, int n)
{
    if (n == 0)
    {
        for (int i = 0; i < cicli; i++)
            cout << "* ";
        cout << endl;
    }
    else
        stampa_asterischi(cicli+n*n, --n);
}

int main()
{
    // stampa 1+4+9+16 asterischi
    stampa_asterischi(0, 5);
    return(0);
}