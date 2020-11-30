#include <iostream>
using namespace std;

// ricorsione
int funz(int n)
{
    if (n == 0) return 1;
    if(n < 0) return 0;
    return (funz(n-1)*2 +1);
}

// iterativo
int funz2(int n)
{
    int ris = 1;
    while(n != 0)
    {
        ris = ris*2+1;
        n--;
    }
    return ris;
}

int main()
{
    int n;
    cin >> n;
    cout << funz(n) << endl;
    cout << funz2(n) << endl;
    return 0;
}