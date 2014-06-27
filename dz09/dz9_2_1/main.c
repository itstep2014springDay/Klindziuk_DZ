// Ёлочка
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("N=");
    scanf("%d",&n);
    //n=4;
    for (int k=1; k<=n; ++k)
    {
        for (int i=1; i<=k+1; ++i)
        {
            for (int j=1; j<=n-i+1; ++j)
            {
                printf(" ");
            }
            for (int j=1; j<=2*i-1; ++j)
            {
                if (j==1 || i==k+1 || j==2*i-1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    for (int j=1; j<=n-1; ++j)
    {
        printf(" ");
    }
    printf("# #\n");
    for (int j=1; j<=n-1; ++j)
    {
        printf(" ");
    }
    printf("# #\n");
    return 0;
}
