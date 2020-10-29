#include <iostream>
using namespace std;

void init_str(char arr[], int length)
{
    int k;
    for (int i = 0; i < length-1; i++){
        arr[i] = rand()%10+97;
    	cout << arr[i] << ' ';
    }
    arr[length-1] = '\0';
    cout << endl;
}

int init_len(int L){
	return(rand() % L);
}

void stampa(char arr[])
{
    int i = 0;

    while (arr[i] != '\0')
    {
        cout << arr[i] << ' ';
        i++;
    }
    
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int length = 30, i = 0;
    
    char A[length];
    init_str(A,init_len(length));

    char B[length];
    init_str(B,init_len(length));


    cout << "Ordine alfabetico: " << endl;

    while (A[i] == B[i])    i++;
    
    if (A[i] < B[i])
    {
        stampa(A);
        stampa(B);
    }
    else
    {
        stampa(B);
        stampa(A);
    }
    
    return(0);
}