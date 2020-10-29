#include <iostream>
#include <cstdlib>
using namespace std;

int l_parola(char arr[])
{
    int i = 0;
    while(arr[i] != '\0') ++i;
    return(i);
}

void init_str(char arr[], int length)
{
    int k;
    for (int i = 0; i < length; i++){
    	if(rand()%2==0)
            arr[i] = rand()%27+65;
        else
            arr[i] = rand()%27+97;
    	cout << arr[i] << ' ';
    }
    arr[length] = '\0';
    cout << endl;
}

int init_len(int L){
	return(rand() % L);
}


int main()
{
    srand(time(NULL));
    int length = 30;
    char A[length];
    init_str(A,init_len(length));

    char B[length];
    init_str(B,init_len(length));

    char C[length];
    init_str(C,init_len(length));

    int l_a = l_parola(A);
    int l_b = l_parola(B);
    int l_c = l_parola(C);

    cout << "Lungezza A: " << l_a << endl;
    cout << "Lungezza B: " << l_b << endl;
    cout << "Lungezza C: " << l_c << endl;

    if (l_a > l_b)
        if (l_a > l_c)  cout << "La stringa A è la più lunga";
        else            cout << "La stringa C è la più lunga";
    else if (l_b > l_c) cout << "La stringa B è la più lunga";
    else                cout << "La stringa C è la più lunga";

    cout << endl;

    return(0);
}