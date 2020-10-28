#include "mathe.h"
using namespace std;

int main(){

    int n;
    cout << "Inserire un numero: ";
    cin >> n;

    cout << "Parte intera della radice quadrata: " << algebra::sqrt(n) << endl;
    cout << "Parte intera del logogaritmo in base 2: " << algebra::log2(n) << endl;

    return(0);
}