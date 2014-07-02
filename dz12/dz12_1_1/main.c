// Найдите квадратный корень методом деления пополам
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,a,b,m,eps=0.0001,fa,fb,fm;
    printf("x=");
    scanf("%lf",&x);
    a=0.0;
    fa=a*a-x;
    b=x;
    fb=b*b-x;
    do
    {
        m=(a+b)/2.0;
        fm=m*m-x;
        if (fabs(fm)<eps)
        {
            break;
        }
        else
        {
            if (fa*fm<0)
            {
                fb=fm;
                b=m;
            }
            else
            {
                fa=fm;
                a=m;
            }
        }
    }
    while (b-a>eps);
    printf("sqrt(x)=%f",m);
    return 0;
}
