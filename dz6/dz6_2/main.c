#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,m,n,gcd,lcm;
    printf("A=");
    scanf("%d",&a);
    printf("B=");
    scanf("%d",&b);
    m=a;
    n=b;
    while (m!=n) {
        if (m>=n)
            {m=m-n;}
        else
            {n=n-m;}
    }
    gcd=m;
    lcm=a*b/gcd;
    printf("GCD=%d\nLCM=%d\n",gcd,lcm);
    return 0;
}
