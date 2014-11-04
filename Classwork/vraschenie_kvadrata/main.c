#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int w;
    printf("Enter odd number\n");
    scanf("%d",&w);
    while (w%2==0)
    {
        printf("Enter odd number\n");
        scanf("%d",&w);
    }
    int r=w/4-1;
    double phi=0.0, dt=3.1416/180.0;
    while (1)
    {
        system("cls");
        for (int i=0; i<w; ++i)
        {
            for (int j=0; j<w; ++j)
            {
                double x=(j-w/2)/(double) r;
                double y=(i-w/2)/(double) r;
                int needPrint =-sin(phi)*x+cos(phi)*y<=1.0 &&
                               sin(phi)*x-cos(phi)*y<=1.0 &&
                               cos(phi)*x+sin(phi)*y<=1.0 &&
                               -cos(phi)*x-sin(phi)*y<=1.0;
                printf("%c",needPrint?'#':' ');
            }
            printf("\n");
        }
        phi+=dt;
    }
    return 0;
}
