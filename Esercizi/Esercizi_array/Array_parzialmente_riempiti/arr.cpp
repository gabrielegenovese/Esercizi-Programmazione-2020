#include <iostream>
using namespace std;

int main()
{
    int x, length = 100, i = 0;
    bool get0 = true;
    int arr[length];

    while (get0 && (i<length))
    {
        cout << "Per smetttere inserire 0\nInserire il numero nell'array in posizione " << i << ": ";
        cin >> x;
        if (x == 0)
        {
            get0 = false;
        }else
        {
            arr[i] = x;
            ++i;
        }
    }

    for (int j = i-1; j >= 0; j--)
    {
        cout << arr[j] << endl;
    }
    
    return(0);
}