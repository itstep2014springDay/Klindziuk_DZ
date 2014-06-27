// Расчёт косинуса
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps=0.0001;
    printf("   x\tmycos(x)\tcos(x)\t\tmycos(x)-cos(x)\n\n");
    for (double x=-2.0; x<2.1; x+=0.1)
    {
        double sum=1, addition=1,cs;
        int i=2;
        while (fabs(addition)>eps)
        {
            addition*=(-1)*x*x/((i-1)*i);
            sum+=addition;
            i+=2;
        }
        cs=cos(x);
        printf(" % .1f\t% f\t% f\t% f\t\n",x,sum,cs,sum-cs);
    }
    return 0;
}
