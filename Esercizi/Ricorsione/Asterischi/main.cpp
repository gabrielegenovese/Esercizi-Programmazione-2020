#include <iostream>
using namespace std;

// scrivere una funzione ricorsiva che prende n e stampa un numero di
// asterischi uguale alla somma dei quadrati dei primi n-numeri naturali
void stampa_asterischi_somma2(int cicli, int n)
{
    if (n == 0)
    {
        for (int i = 0; i < cicli; i++)
            cout << "* ";
        cout << endl;
    }
    else
        stampa_asterischi_somma2(cicli+n*n, --n);
}

// stampa il n^2 asterischi senza iterazioni e doppie funzioni
void stampa_asterischi2(int n)
{
    if(n > 0) n = -n*n;
    if(n < 0)
    {
        cout << "* ";
        stampa_asterischi2(n+1);
    }
}

int main()
{
    int temp, n;
    cout << "Inserire un numero: ";
    cin >> n;
    temp = n > 0 ? n : -n;

    cout << "Stampa di " << n << "^2 asterischi: ";
    stampa_asterischi2(temp);

    cout << "\nStampa della somma dei quadrati dei primi " << n << "-numeri naturali: ";
    //stampa_asterischi_somma2(0, temp);  // se si vuole stampare solo i precedenti
    stampa_asterischi_somma2(0, temp+1); //se si vuole aggiungere anche n^2

    return(0);
}