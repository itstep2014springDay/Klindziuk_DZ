#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,l,rez,i;
    printf("X=");
    scanf("%d",&x);
    printf("L=");
    scanf("%d",&l);
    rez=1;
    i=0;
    while (rez<=l) {
        rez=rez*x;
        ++i;
    }
    i=i-1;
    printf("P=%d",i);
    return 0;
}
