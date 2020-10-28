#include <iostream>
using namespace std;

int main()
{
    int h, spazi, stars;
    cout << "Inserisci l'altezza del triangolo: ";
    cin >> h;
    
    for (int i = h; i >= 0; i--)
    {
        for (spazi = 0; spazi < h-i; spazi++)
        {
            cout << " ";
        }

        for (stars = 0; stars < 2 * i - 1; stars++)
        {
            cout << "*";
        }

        cout << "\n";
    }
    
}