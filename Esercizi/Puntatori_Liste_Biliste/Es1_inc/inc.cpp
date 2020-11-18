#include <iostream>
using namespace std;

typedef int *p_int;

int main()
{
    int num = 0;
    p_int x, y = &num;

    cout << "Numero: " << num << endl;

    (*x)++;
    (*y)++;

    cout << "Numero: " << num << endl;

    return(0);
}