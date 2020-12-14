#include <iostream>
using namespace std;

/*
es 1:
La funzione seguente dovrebbe implementare la funzione
di libreria strcat, ma contiene degli errori. Dire quali e
quanti errori, e darne una versione corretta. Giustificare la
risposta.

void strcat(char dest[], char src[]){
    int i,j;
    i=0;
    while(dest[i]!='\0')
        i++;
    while(src[j]!='\0'){
        dest[i]=src[j];
        j++;
    }
}
*/

void strcat(char dest[], char src[])
{
    int i = 0, j = 0;
    while(dest[i] != '\0') i++;

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}


int main()
{
    char c[20];
    cin >> c;
    strcat(c,(char *)"gino");
    cout << c << endl;
}