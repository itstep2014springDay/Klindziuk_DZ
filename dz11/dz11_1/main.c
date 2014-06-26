// Расчёт экспоненты
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double eps=0.0001;
    printf("   x\tmyexp(x)\texp(x)\t\tmyexp(x)-exp(x)\n\n");
    for (double x=-2.0; x<2.1; x+=0.1)
    {
        double sum=1.0, addition=1.0,ex;
        int i=1;
        while (fabs(addition)>eps)
        {
            addition*=x/i;
            sum+=addition;
            ++i;
        }
        ex=exp(x);
        printf(" % .1f\t% f\t% f\t% f\t\n",x,sum,ex,sum-ex);
    }
    return 0;
}
