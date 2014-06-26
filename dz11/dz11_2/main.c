// Расчёт синуса
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps=0.0001;
    printf("   x\tmysin(x)\tsin(x)\t\tmysin(x)-sin(x)\n\n");
    for (double x=-2.0; x<2.1; x+=0.1)
    {
        double sum=x, addition=x,sn;
        int i=3;
        while (fabs(addition)>eps)
        {
            addition*=(-1)*x*x/((i-1)*i);
            sum+=addition;
            i+=2;
        }
        sn=sin(x);
        printf(" % .1f\t% f\t% f\t% f\t\n",x,sum,sn,sum-sn);
    }
    return 0;
}
