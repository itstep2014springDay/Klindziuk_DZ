#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,r;
    r=20;
    for (i=0;i<=2*r;++i)
    {
        for (j=0;j<=2*r;++j)
        {
            if ((i-r)*(i-r)+(j-r)*(j-r)<=r*r)
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
    return 0;
}
