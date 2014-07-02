// Отношение соседних членов ряда Фибоначчи
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,b,s;
    double d1,d2,d,eps=0.00001;
    a=1;
    b=1;
    d1=(double) a/b;
    s=a+b;
    d2=(double) b/s;
    while (fabs(d1-d2)>eps)
    {
        d1=(double) a/b;
        s=a+b;
        d2=(double) b/s;
        a=b;
        b=s;
    }
    printf("d=%g\n",d2);
//---------------------------------
    printf("n=");
    scanf("%d",&n);
    while (n<3)
    {
        printf("n=");
        scanf("%d",&n);
    }
    a=1;
    b=1;
    printf("\tn\ta\tb\ta/b\n");
    printf("\t--------------------------------\n");
    printf("\t1\t1\t-\t-\n");
    for (i=2; i<=n; ++i)
    {
        s=a+b;
        d=(double) b/s;
        printf("\t%d\t%d\t%d\t%f\n",i,b,s,d);
        a=b;
        b=s;
    }
    return 0;
}
