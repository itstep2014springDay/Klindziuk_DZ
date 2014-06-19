// Перевод в произвольную систему, до 16-иричной
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,b,i,y,a,z;
    printf("Vvedite chislo X\n");
    scanf("%d",&x);
    printf("Vvedite sistemy schisleniya (b<=16)\n");
    scanf("%d",&b);
    y=0;
    i=1;
    while (x>0)
    {
        z=x%b;
        y=z+y*b;
        i=i*b;
        x=x/b;
    }
    printf("New X=");
    while (y>0)
    {
        z=y%b;
        y=y/b;
        switch (z)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d",z);
        }
    }
    return 0;
}
