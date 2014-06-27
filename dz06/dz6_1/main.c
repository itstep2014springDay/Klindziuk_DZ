#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,gcd;
    printf("A=");
    scanf("%d",&a);
    printf("B=");
    scanf("%d",&b);
    while (a!=b) {
        if (a>=b)
            {a=a-b;}
        else
            {b=b-a;}
    }
    gcd=a;
    printf("GCD=%d",gcd);
    return 0;
}
