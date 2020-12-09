#include <iostream>
using namespace std;

// ricorsiva
void stampa_pari(int n)
{
    n--;
    if(n <= 0){}
    else
    {
        if(n%2 == 0 && n%4 != 0)
            cout << n << endl;
        stampa_pari(n);
    }
}

// iterativa
void stampa_pari2(int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        if(i%2 == 0 && i%4 != 0)
            cout << i << endl;
    }
}

int main()
{
    int n;
    cout << "Inserire numero: ";
    cin >> n;
    stampa_pari2(n);
    return 0;
}