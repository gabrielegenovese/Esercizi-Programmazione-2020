#include <iostream>
using namespace std;

// ricorsione
int fibo(int n, int curr = 1, int prev = 0)
{
    if (n == 0) return prev;
    else return fibo(n-1, curr+prev, curr);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}