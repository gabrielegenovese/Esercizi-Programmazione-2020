#include "mathe.h"

namespace algebra
{
    int sqrt(int n)
    {
        int temp = 1;

        if (n < 0) return(-1);
        else
        {
            while (temp*temp < (n/2))
            {
                ++temp;
            }
            return(--temp);
        }
    }

    int log2(int n)
    {
        int x = 1, c = 0;
        while (x*2 <= n)
        {
            x *= 2;
            c++;
        }
        return(c);
    }
}