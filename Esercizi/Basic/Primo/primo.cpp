#include <iostream>
using namespace std;

int main()
{
    int n, temp, c = 0;
    cout << "Inserire un numero" << endl;
    cin >> n;
    temp = n/2;

    while (temp > 1)
    {
        if(n % temp == 0)
            temp = 1;
        temp--;
    }

    if (temp)
        cout << "è primo" << endl;
    else
        cout << "Non è primo" << endl;
    
}