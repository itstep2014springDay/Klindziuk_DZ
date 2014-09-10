// решение уравнения методом деления отрезка пополам
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double dichotomia(double a, double b, double(*f)(double))
{
    assert(b>a);
    assert(f(b)*f(a)<0);
    double eps=0.00001;
    while (b-a>eps)
    {
        double m=(a+b)/2.0;
        if(f(m)==0.0)
            return m;
        if(f(a)*f(m)<0.0)
            b=m;
        else
            a=m;
    }
    return (a+b)/2.0;
}

double quadraticEquation(double x)
{
    return x*x-5*x+6;
}

int main()
{
    double x;
    x=dichotomia(0.0,2.5,quadraticEquation);
    printf("X=%f",x);
    return 0;
}
