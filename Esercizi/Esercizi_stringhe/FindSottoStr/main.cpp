#include <iostream>
using namespace std;

bool is_ch_gh_sottostr(char arr[], int length)
{
    int i = 0;
    while (i < length && ((arr[i] != 'c' || arr[i] != 'g') && arr[i+1] != 'h')) i++;

    if (i == length)  return(false);
    else              return(true);   
}

int l_parola(char arr[])
{
    int i = 0;
    while(arr[i] != '\0') ++i;
    return(i);
}

int main()
{
    int length = 30;
    char str[length];

    cout << "Inserire una stringa (massimo 30 caratteri): ";
    cin >> str;

    bool temp = is_ch_gh_sottostr(str, length);

    if (temp)   cout << "C'è ch o gh nella stringa" << endl;
    else        cout << "Non c'è ch o gh nella stringa" << endl;

    return(0);
}