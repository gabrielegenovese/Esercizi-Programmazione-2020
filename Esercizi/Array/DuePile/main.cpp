#include <iostream>
using namespace std;

bool is_empt(int cursor1, int cursor2, int n)
{
    if(n == 1){
        if(cursor1 == 0)  return(true);
        else            return(false);
    }else{
        if(cursor2 == 9)    return(true);
        else                return(false);
    }
}

bool push(int* arr, int length, int& cursor1, int& cursor2, int x, int n)
{
    if (cursor2 - cursor1 < 0) return(false);
    else
    {
        if (n == 1)
        {
            arr[cursor1] = x;
            cursor1++;
        }else
        {
            arr[cursor2] = x;
            cursor2--;
        }
        return(true);
    }
}

int pop(int* arr, int& cursor1, int& cursor2, int n)
{   
    if (n == 1)
    {
        if (cursor1 > 0){
            cursor1--;
            int n = arr[cursor1];
            return(n);
        }
    }
    else
    {
        if (cursor2 < 9){
            cursor2++;
            int n = arr[cursor2];
            return(n);
        }
    }
    return(0);
}

void stampa(int arr[], int cursor1, int cursor2, int length, int n)
{
    cout << "Pila " << n << ":\t";
    if(n == 1)
    {
        for (int i = 0; i < cursor1; i++)
        {
            cout << arr[i] << "\t";
        }
    }
    else
    {
        for (int i = length-1; i > cursor2; i--)
        {
            cout << arr[i] << "\t";
        }
    }
    cout << endl;
}

int main()
{
    int n, x, length = 10, cursor1 = 0, cursor2 = length-1;
    int arr[length];

    cout << "Due pile di lunghezza " << length/2 << endl;
    do
    {
        do
        {
            cout << "Selezionare la pila su cui operare (1 o 2): ";
            cin >> n;
        } while(n < 1 && n > 2);
        
        cout << "Si è scelto la pila " << n << endl;
        stampa(arr, cursor1, cursor2, length, n);
        
        cout << "Inserire un numero per decidere cosa fare" << endl <<
                "0. Termina programma\n1. is_empty\n2. push\n3. pop\n";
        cin >> x;

        switch (x)
        {
            case 0:
                break;
            case 1:
                if (is_empt(cursor1, cursor2, n))  cout << "is_empty: true\n";
                else                            cout << "is_empty: false\n";
                break;
            case 2:
                cout << "Inserire un numero: ";
                cin >> x;
                if(!push(arr, length, cursor1, cursor2, x, n)) cout << "overflow o non ci sono elementi\n";
                break;
            case 3:
                cout << "Pop: " << pop(arr, cursor1, cursor2, n) << endl;
                break;
            default:
                break;
        }
    } while (x != 0);
    
    return(0);
}