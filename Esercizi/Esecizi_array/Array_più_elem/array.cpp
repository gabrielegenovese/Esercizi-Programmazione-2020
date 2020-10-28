#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n, prec;
    cout << "Inserire la lunghezza dell'array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Inserire il numero nell'array in posizione " << i << ": ";
        cin >> arr[i];
    }

    sort(arr,arr+n);  

    cout << "Stampa dell'array senza doppioni: " << endl;

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] != arr[i+1]) cout << arr[i] << endl;
    }

    cout << arr[n-1] << endl;

    return(0);
}