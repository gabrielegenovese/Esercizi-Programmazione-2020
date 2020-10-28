#include <iostream>
using namespace std;

int main()
{
    int n, ultimo = 0, ris = 1;
    cout << "Inserire un numero" << endl;
    cin >> n;

    while (n-- > 2)
    {
        ris = ris + ultimo;
        ultimo = ris-ultimo;
    }
    
    cout << ris;
}