#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

int main()
{
    const int n=10; //max
    for (int a=1; a<n; ++a)
    {
        for (int c=0; c<n; ++c)
        {
            for (int m=c+1; m<=n; ++m)
            {
                if (gcd(c,m)==1)    // 1-е условие
                {
                    for (int p=2; p<=m/2; ++p)
                    {
                        if (m%p==0 && primeNumber(p) && (a-1)%p==0)   // 2-е условие
                        {
                            if (m%4==0 && (a-1)%4==0)   // 3-е условие
                                printf("a=%d c=%d m=%d\t\tp=%d\n",a,c,m,p);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
