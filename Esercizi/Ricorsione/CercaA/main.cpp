#include <iostream>
using namespace std;

int serch_a(char s[], int start = 0)
{
    if(s[0] == '\0') return start;
    
    if(s[0] == 'a')
        return serch_a(++s, ++start);
    return serch_a(++s, start);
}

int main()
{
    char s[] = { 'a', 'b', 'a', 'C', 'o', 'a'};

    cout << serch_a(s) << endl;

    return 0;
}