#include <stdio.h>
#include <stdlib.h>

int main()
{
    double rez;
    int x,p,i;
    printf("X=");
    scanf("%d",&x);
    printf("p=");
    scanf("%d",&p);
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
    printf("Rez=%f",rez);
    return 0;
}
