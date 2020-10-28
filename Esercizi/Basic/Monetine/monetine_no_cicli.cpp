#include <iostream>
#include <math.h>
using namespace std;

int main(){

    double euro, temp = 0.0;
    int due = 0, uno = 0, cinquanta = 0, venti = 0, dieci = 0, cinque = 0, due_c = 0, un_c = 0;
    
    cout << "Inserisci un valore: ";
    cin >> temp;

    due += temp/2;
    temp -= due*2;
    uno += temp;
    temp -= uno;
    temp *= 100;
    cinquanta += temp/50;
    temp -= cinquanta*50;
    venti += temp/20;
    temp -= venti*20;
    dieci += temp/10;
    temp -= dieci*10;
    cinque += temp/5;
    temp -= cinque*5;
    due_c += temp/2;
    temp -= due_c*2;
    un_c += temp;

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