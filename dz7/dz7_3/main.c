// Рисование ромба по заданной диагонали (нечётное число)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,i,j;
    printf("d=");
    scanf("%d",&d);
    while (d%2==0)
    {
        printf("ERROR!\nd=");
        scanf("%d",&d);
    }
    for (i=1;i<=d/2+1;++i)
    {
        for (j=1;j<=d/2-i+1;++j)
        {
            printf(" ");
        }
        for (j=1;j<=2*i-1;++j)
        {
            printf("#");
        }
        printf("\n");
    }

    for (i=1;i<=d/2;++i)
    {
        for (j=0;j<i;++j)
        {
            printf(" ");
        }
        for (j=1;j<=d-2*i;++j)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
