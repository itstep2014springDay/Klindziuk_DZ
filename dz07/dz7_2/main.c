// Разложение на простые множители
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,st,m,f;
    printf("N=");
    scanf("%d",&n);
    while (n==1)
    {
        printf("ERROR!\nN=");
        scanf("%d",&n);
    }
    while (n!=1)
    {
        st=0;
        for (i=2; i<=n; ++i)
        {
            if (n%i==0)
            {
                ++st;
                m=i;
                printf("%d ",m);
                n=n/m;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
