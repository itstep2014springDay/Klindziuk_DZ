#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,p,rez,i;
    printf("X=");
    scanf("%d",&x);
    printf("p=");
    scanf("%d",&p);
    rez=1;
    i=0;
    do {
        rez=rez*x;
        ++i;
    } while (i!=p);
    printf("Rez=%d",rez);
    return 0;
}
