// Сумма <>100
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,x,s;
    printf("N=");
    scanf("%d",&n);
    s=0;
    for (i=1; i<=n; ++i)
    {
        printf("x[%d]=",i);
        scanf("%d",&x);
        s=s+x;
    }
    if (s>100)
    {
        printf("Your sum of numbers >100");
    }
    else
    {
        if (s<100)
        {
            printf("Your sum of numbers <100");
        }
        else
        {
            printf("sum=%d",s);
        }
    }
    return 0;
}
