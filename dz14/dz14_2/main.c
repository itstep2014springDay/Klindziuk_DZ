// Перевод в произвольную систему, до 36-ричной
#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

int main()
{
    int x,b;
    printf("Vvedite chislo X\n");
    scanf("%d",&x);
    printf("Vvedite sistemy schisleniya (b<=36)\n");
    scanf("%d",&b);
    while (b<2 || b>36)
    {
        printf("ERROR! Vvedite sistemy schisleniya (b<=36)\n");
        scanf("%d",&b);
    }
    printf("New X=");
    convert36(x,b);
    return 0;
}
