#include <iostream>
using namespace std;

// scrivere write_vertical in maniera che le cifre sono
// stampate dalla meno significativa alla più significativa

// ricorsiva
void r_write_vertical(int n)
{
    if (n <= 9 && n >= 0)
        cout << n << endl;
    else
    {
        cout << n%10 << endl;
        r_write_vertical(n/10);
    }
}

// iterativa
void i_write_vertical(int n)
{
    while (n != 0)
    {
        cout << n%10 << endl;
        n = n/10;
    }
}

int main()
{
    r_write_vertical(12300);
    cout << "-----" << endl;
    i_write_vertical(12301);
    
    return(0);
}