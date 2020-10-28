#include <iostream>
using namespace std;

bool is_empt(int cursor)
{
    if(cursor > 0)    return(false);
    else                return(true);
}

bool push(int* arr, int& cursor, int length, int n)
{
    if (cursor == length) return(false);
    else
    {
        arr[cursor] = n;
        cursor++;
        return(true);
    }
}

int pop(int* arr, int& cursor)
{   
    if (cursor > 0){
        cursor--;
        int n = arr[cursor];
        return(n);
    }
    return(0);
}

void stampa(int* arr, int& cursor, int length)
{
    cout << "Pila:\t";

    for (int i = 0; i < cursor; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;
}

int main()
{
    int n, x = 0, length = 5, cursor = 0;
    int arr[length];

    cout << "Pila di lunghezza " << length << endl;
    do
    {
        
        cout << "Inserire un numero per decidere cosa fare" << endl <<
                "0. Termina programma\n1. is_empty\n2. push\n3. pop\n4. stampa\n";
        cin >> x;

        switch (x)
        {
            case 0:
                break;
            case 1:
                if (is_empt(cursor))    cout << "is_empty: true\n";
                else                    cout << "is_empty: false\n";
                break;
            case 2:
                cout << "Inserire un numero: ";
                cin >> n;
                if(!push(arr, cursor, length, n)) cout << "overflow o non ci sono elementi\n";
                break;
            case 3:
                cout << "Pop: " << pop(arr, cursor) << endl;
                break;
            case 4:
                stampa(arr, cursor, length);
            default:
                break;
        }
    } while (x != 0);
    
    return(0);
}