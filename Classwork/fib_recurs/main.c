#include <stdio.h>
#include <stdlib.h>

int fibIterat(int n);
int fibRecurs(int n);

int main()
{
    int choise,n;
    printf("Enter 0 (fibIterat) or 1 (fibRecurs)\n");
    scanf("%d", &choise);
    printf("Enter N\n");
    scanf("%d", &n);
    if (choise)
        printf("%d ",fibRecurs(n));
    else
        printf("%d ",fibIterat(n));
    return 0;
}

int fibIterat(int n)
{
    int a=1,b=0,c;
    for (int i=1; i<=n; ++i)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int fibRecurs(int n)
{
    if (1==n || 2==n)
    {
        return 1;
    }
    return fibRecurs(n-1)+fibRecurs(n-2);
}
