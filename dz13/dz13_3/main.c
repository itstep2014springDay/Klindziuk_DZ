#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main()
{
    int n,i,j;
    printf("N=");
    scanf("%d",&n);
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            if (gcd(i,j)==1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

int gcd(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b)
            a=a%b;
        else
            b=b%a;
    }
    return (a+b);
}
