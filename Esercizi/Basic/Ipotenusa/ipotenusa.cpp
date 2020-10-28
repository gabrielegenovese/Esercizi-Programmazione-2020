#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double c1, c2, ipo;
    cout << "Inserire il primo cateto: ";
    cin >> c1;
    cout << "Inserire il secondo cateto: ";
    cin >> c2;

    ipo = sqrt( c1*c1 + c2*c2 );
    cout << "Ipotenusa: " << ipo;
}