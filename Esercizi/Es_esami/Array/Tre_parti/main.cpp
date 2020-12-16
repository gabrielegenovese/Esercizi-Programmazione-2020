/*
ESERCIZIO 19/2/2020
Scrivere una funzione che prende un array di interi e lo trasforma come segue:
 la prima parte dell’array finale contiene tutti i numeri maggiori di 1000; 
 la seconda parte contiene tutti i numeri negativi;
 la terza parte contiene tuttii numeri compresi tra 0 e 1000.
Non si richiede che le tre parti siano ordinate.
*/

#include <iostream>
using namespace std;

void f(int a[], int l){
    int cursor = 0, tmp;
    for (int i = 0; i < l; i++){
        if(a[i] > 1000){
            tmp = a[i];
            a[i] = a[cursor];
            a[cursor] = tmp;
            cursor++;
        }
    }
    for (int i = cursor; i < l; i++){
        if(a[i] < 0){
            tmp = a[i];
            a[i] = a[cursor];
            a[cursor] = tmp;
            cursor++;
        }
    }
}


int main()
{
    int a[] = {1006,2,-1,4,-2,1001,2,-54,1002,5,-53,2};
    f(a,12);
    for (int i = 0; i < 12; i++)
    {
        cout<< a[i] << endl;
    }
}