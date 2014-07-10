// Функция возведения в степень
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myPow(double x, int p);

int main()
{
    double rez;
    int x,p,i;
    printf("X=");
    scanf("%d",&x);
    printf("p=");
    scanf("%d",&p);
    printf("MyRez=\t%f\n",myPow(x,p));
    printf("Rez=\t%f",pow(x,p));
    return 0;
}

double myPow(double x, int p)
{
    double rez;
    int i;
    rez=1;
    i=0;
    if (p>0)
    {
        do
        {
            rez=rez*x;
            ++i;
        }
        while (i!=p);
    }
    else
    {
        if (p<0)
        {
            do
            {
                rez=rez*x;
                --i;
            }
            while (i!=p);
            rez=1/rez;
        }
        else
        {
            rez=1;
        }
    }
    return rez;
}
