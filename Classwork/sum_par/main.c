#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int i);

int main()
{
    int i,j,a,b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    for (i=a; i<b; ++i)
    {
        for (j=i+1; j<=b; ++j)
        {
            if (sumOfDigits(i)==sumOfDigits(j))
                printf("%d %d\n",i,j);
        }
    }
    return 0;
}

int sumOfDigits(int i)
{
    int sum=0;
    while (i)
    {
        sum+=i%10;
        i/=10;
    }
    return sum;
}
