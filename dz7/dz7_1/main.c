// Проверка является ли число простым
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,flag;
    printf("N=");
    scanf("%d",&n);
    while (n==1)
    {
        printf("ERROR!\nN=");
        scanf("%d",&n);
    }
    flag=0;
    for (i=2;i<=n/2;++i)
    {
        if (n%i==0)
        {
            ++flag;
        }
    }
    if (flag==0)
    {
        printf("Prostoe");
    }
    else
    {
        printf("Sostavnoe");
    }
    printf("\n");
    return 0;
}
