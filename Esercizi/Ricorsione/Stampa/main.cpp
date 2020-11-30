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
    if (n%2==1)
        n--;

    while (n > 0)
    {
        n -= 2;
        if (n % 4 != 0) cout << n << endl;
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