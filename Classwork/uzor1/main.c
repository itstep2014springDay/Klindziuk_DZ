#include <stdio.h>
#include <stdlib.h>

int main()
{

    int w,h,i,j,k;
    printf("w=");
    scanf("%d",&w);
    printf("h=");
    scanf("%d",&h);

    //w=3;
    //h=1;
    for (i=1;i<=h;++i)
    {
        for (j=1;j<=w;++j)
        {
            for (k=2;k<=j;++k)
            {
                printf(" ");
            }
            printf("#\n");
        }
        for (j=w;j>2;--j)
        {
            for (k=1;k<=j-2;++k)
            {
                printf(" ");
            }
            printf("#\n");
        }
    }
    printf("#\n");
    return 0;
}
