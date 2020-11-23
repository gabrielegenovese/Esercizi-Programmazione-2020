#include <iostream>
using namespace std;

int l_parola(char arr[])
{
    int i = 0;
    while(arr[i] != '\0') ++i;
    return(i);
}

/*

sigma = 0 | s | s sigma s
s = 'a' ... 'z'

c[0] = vero
c[s] = vero
c[yXz] = if (y == z) c[X] else false

*/

bool palin(char c[], int length)
{
    if (length == 0 || length == 1) return(true);
    else
    {
        if(c[0] == c[length-1]) return(palin(c+1, length-2));
        else return(false);
    }
}

int main()
{

    char c[100];
    cout << "Inserire una stringa con al centro 0 (MAX 100 caratteri): ";
    cin >> c;
    int length = l_parola(c);
    bool tmp = palin(c, length);
    
    if (tmp) cout << "La stringa inserita è palindroma" << endl;
    else cout << "La stringa inserita non è palindroma" << endl;
    
    return(0);
}