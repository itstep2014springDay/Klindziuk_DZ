#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,x,d,w;
    w=20; // длина прогрессбара
    x=100;// проценты
    for (i=0;i<=x;++i)
    {
        printf("Progressbar is RUN!     ");
        printf("[");
        d=i/(100/w);                                  // масштаб прогрессбара
        for (j=1;j<=d;++j)
        {
            printf("#");
        }
        for (j=1;j<=x/(100/w)-d;++j)
        {
            printf("-");
        }
        printf("] %3d%%",i);
        //delay
        for (k=0;k<0.33e+8;++k) {}
        printf("\r");
    }
    printf("\n\n");
    printf("Hello world!\n");
    return 0;
}
