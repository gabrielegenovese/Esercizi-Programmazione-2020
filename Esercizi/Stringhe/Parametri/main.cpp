#include <iostream>
using namespace std;

void parola(char str[], char c, char dest[])
{
    int j = 0, i = 1;

    // trovo la parola (per trovare la prima parola bisogna mettere prima uno spazio)
    while (str[i] != '\0' && (str[i] != c || str[i-1] != ' ')) i++;
    
    // la inserisco in dest
    while (str[i] != '\0' && str[i] != ' ')
    {
        dest[j] = str[i];
        i++;
        j++;
    }

    dest[j] = '\0';
}

void stampa(char arr[])
{
    int i = 0;

    while (arr[i] != '\0')
    {
        cout << arr[i] << ' ';
        i++;
    }
    
    cout << endl;
}

int main()
{
    int length = 30;

    char str[] = " ciao mi chiamo gabriele e sono un informatico\0";
    char dest[length], find;

    cout << str << endl;
    cout << "Inserire un carattere: ";
    cin >> find;
    parola(str, find, dest);
    stampa(dest);
    
    return(0);
}