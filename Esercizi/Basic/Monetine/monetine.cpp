#include <iostream>
#include <math.h>
using namespace std;

int main(){

    double euro, temp = 0.0;
    int due = 0, uno = 0, cinquanta = 0, venti = 0, dieci = 0, cinque = 0, due_c = 0, un_c = 0;
    
    cout << "Inserisci un valore: ";
    cin >> euro;

    while (euro >= (temp + 2.0))
    {
        temp += 2.0;
        due++;
    }
    while (euro >= (temp + 1.0))
    {
        temp += 1.0;
        uno++;
    }
    while (euro >= (temp + 0.50))
    {
        temp += 0.50;
        cinquanta++;
    }
    while (euro >= (temp + 0.20))
    {
        temp += 0.20;
        venti++;
    }
    while (euro >= (temp + 0.10))
    {
        temp += 0.10;
        dieci++;
    }
    while (euro >= (temp + 0.05))
    {
        temp += 0.05;
        cinque++;
    }
    while (euro >= (temp + 0.02))
    {
        temp += 0.02;
        due_c++;
    }
    while (euro >= (temp + 0.01))
    {
        temp += 0.01;
        un_c++;
    }
    

    cout << "Input inserito: " << temp << endl;
    cout << "Monete da 2 euro: " << due << endl;
    cout << "Monete da 1 euro: " << uno << endl;
    cout << "Monete da 50 cent: " << cinquanta << endl;
    cout << "Monete da 20 cent: " << venti << endl;
    cout << "Monete da 10 cent: " << dieci << endl;
    cout << "Monete da 5 cent: " << cinque << endl;
    cout << "Monete da 2 cent: " << due_c << endl;
    cout << "Monete da 1 cent: " << un_c << endl;
    
    return(0);
}