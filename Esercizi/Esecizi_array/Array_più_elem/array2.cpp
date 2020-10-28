#include <iostream>
using namespace std;

void stampaSenzaDuplicati(int arr[], int length)
{
    bool stampa;

    cout << "Stampa dell'array senza duplicati: " << endl;

    for (int i = 0; i < length; i++)
    {
        stampa = true;

        for (int k = i+1; k < length; k++)
        {
            if (arr[i] == arr[k]) stampa = false;
        }

        if(stampa) cout << arr[i] << endl;
        
    } 
}

int main()
{
    int length;
    cout << "Inserire la lunghezza dell'array: ";
    cin >> length;

    int arr[length];

    for (int i = 0; i < length; i++)
    {
        cout << "Inserire il numero nell'array in posizione " << i << ": ";
        cin >> arr[i];
    }  

    stampaSenzaDuplicati(arr, length);

    return(0);
}