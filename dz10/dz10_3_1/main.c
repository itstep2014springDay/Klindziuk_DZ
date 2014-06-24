// Действия с 3-мя чслами
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,rez;
    printf("A=");
    scanf("%d",&a);
    printf("B=");
    scanf("%d",&b);
    printf("C=");
    scanf("%d",&c);
    rez=a+b+c;
    printf("A+B+C=%d\n",rez);
    rez=a-b-c;
    printf("A-B-C=%d\n",rez);
    rez=a*b*c;
    printf("A*B*C=%d\n",rez);
    if (b==0 || c==0)
    {
        printf("A/B/C= ERROR! Division by zero.");
    }
    else
    {
        rez=a/b/c;
        printf("A/B/C=%d\n",rez);
        double rez=(double)a/b/c;
        printf("A/B/C=%.3f\n",rez);
    }
    return 0;
}
