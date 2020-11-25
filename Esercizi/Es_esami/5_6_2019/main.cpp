/*
Scrivere una funzione che prende in input una lista di caratteri e restituisce il numero di
occorrenze della stringa “amar” nella lista di input.
*/

#include <iostream>
using namespace std;

int occorre(char c[])
{
    int i = 0, count = 0;
    while(c[i+3] != '\0')
    {
        if (c[i] == 'a' && c[i+1] == 'm' && c[i+2] == 'a' && c[i+3] == 'r') count++;
        i++;
    }
    return(count);
}

int main()
{

    char c[] = "Ciao amar ciao amaromont amasrea amaaie aeam\0";

    cout << "Occorrenze di amar in '" << c << "': " << occorre(c) << endl;

    return(0);
}