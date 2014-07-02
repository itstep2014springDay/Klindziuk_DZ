// Квадратное уравнение
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a,b,c,d;
    printf("a=");
    scanf("%lf",&a);
    printf("b=");
    scanf("%lf",&b);
    printf("c=");
    scanf("%lf",&c);
    d=b*b-4*a*c;
    if (d<0)
    {
        printf("Net kornei");
    }
    else
    {
        if (d==0)
        {
            double x;
            x=-b/(2.0*a);
            printf("x=%f",x);
        }
        else
        {
            double x1,x2;
            x1=(-b+sqrt(d))/(2.0*a);
            x2=(-b-sqrt(d))/(2.0*a);
            printf("x1=%f\nx2=%f",x1,x2);
        }
    }
    return 0;
}
