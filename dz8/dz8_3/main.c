// Палиндром
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,n2;
    printf("N=");
    scanf("%d",&n);
    m=n;
    n2=0;
    while (m>0)
    {
        n2=n2*10+m%10;
        m=m/10;
    }
    if (n==n2)
        printf("Polimirph");
    else
        printf("Ne polimirph");
    return 0;
}
