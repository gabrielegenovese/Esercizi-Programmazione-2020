#include <iostream>
using namespace std;

int firstDoubleChar(char arr[], int length)
{
    int i = 1, j = 0;

    while (arr[i] != arr[j] && i < length)
    {
        j++;

        if (j == i)
        {
            j = 0;
            i++;
        }
    }

    if (i == length) return(-1);
    else return(i);
}
    
int main()
{
    int pos, length = 10;
    char arr[length];

    for (int i = 0; i < length; i++)
    {
        cout << "Inserire il carattere nell'array in posizione " << i << ": ";
        cin >> arr[i];
    }

    pos = firstDoubleChar(arr, length);

    if (pos == -1)
    {
        cout << "Non ci sono caratteri che occorrono almeno 2 volte" << endl;
    }
    else 
    {
        cout << "Posizione della seconda occorrenza del primo " <<
                "carattere che occorre almeno due volte: " << pos << endl;
    }
    
    return(0);
}