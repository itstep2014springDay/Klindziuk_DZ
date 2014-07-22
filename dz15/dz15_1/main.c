// Линейный конгруэнтный генератор псевдослучайных чисел
#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

int main()
{
    const int n=10;
    int x0,x,choise;
    printf("Enter 1 to WIKI coefficients or 2 to other coefficients\n");
    scanf("%d",&choise);
    switch (choise)
    {
    case 1:
        printf("Enter X0\n");
        scanf("%d",&x0);
        for (int i=1; i<=n; ++i)
        {
            x=myRandWiki(x0);
            printf("%d ",x);
            x0=x;
        }
        break;
    case 2:
        printf("Enter X0\n");
        scanf("%d",&x0);
        for (int i=1; i<=n; ++i)
        {
            x=myRandOther(x0);
            printf("%d ",x);
            x0=x;
        }
        break;
    default:
        printf("Error.");
    }
    return 0;
}
