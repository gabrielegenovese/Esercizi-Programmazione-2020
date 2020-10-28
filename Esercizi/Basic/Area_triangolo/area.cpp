#include <iostream>
using namespace std;

int main()
{
    double base, altezza, area;
    cout << "Inserire base: ";
    cin >> base;
    cout << "Inserire altezza: ";
    cin >> altezza;
    area = (base*altezza)/2;
    cout << "Area: " << area << endl;
}