#include <iostream>
using namespace std;

void f(int a[], const int l, int cursor, int i)
{
    int tmp;
    if(i == l){ return; }
    if(a[i] % 2 == 0)
    {
        tmp = a[cursor];
        a[cursor] = a[i];
        a[i] = tmp;
        cursor++;
    }
    f(a, l, cursor, ++i);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8};
    f(a, 8, 0, 0);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << endl;
    }
    
    return 0;
}
