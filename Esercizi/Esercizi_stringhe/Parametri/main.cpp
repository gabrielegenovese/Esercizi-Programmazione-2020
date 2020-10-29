#include <iostream>
using namespace std;

void parola(char str[], char c, char dest[])
{
    int j = 0,i = 1;
    while (str[i] != '\0' && (str[i] != c || str[i-1] != ' ')) i++;
    
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

    char str[] = "ciao mi chiamo gabriele e sono un informatico\0";
    char dest[length], find;

    cout << str << endl;
    cout << "Inserire un carattere: ";
    cin >> find;
    parola(str, find, dest);
    stampa(dest);
    
    return(0);
}