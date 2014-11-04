#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,i,j,f1,f2,a,b,gcd,n,flag_fib;
    printf("w=");
    scanf("%d",&w);
    printf("h=");
    scanf("%d",&h);
    flag_fib=0;
    a=w;
    b=h;
    while (a!=b)
    {
        if (a>=b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    gcd=a;
    a=w/gcd;
    b=h/gcd;
    f1=5;
    f2=8;
    if (h>w)
    {
        n=h;
    }
    else
    {
        n=w;
    }
    for (i=1; i<=n; ++i)
    {
        if ((a==f1) && (b==f2) || (b==f1) && (a==f2))
        {
            flag_fib=1;
        }
        int f=f1+f2;
        f1=f2;
        f2=f;
    }
    if (flag_fib==1)
    {
        for (i=1; i<=h; ++i)
        {
            for (j=1; j<=w; ++j)
            {
                if (i==1 || i==2 || i==h-1 || i==h)
                {
                    printf("@");
                }
                else if (j==1 || j==2 || j==w-1 || j==w)
                {
                    printf("@");
                }
                else
                {
                    printf(" ");
                }

            }
            printf("\n");
        }
    }
    else
    {
        char symbol;
        symbol = h<w?'#':(h>w?'*':'8');

        for (i=1; i<=h; ++i)
        {
            for (j=1; j<=w; ++j)
            {
                if (i==1 || i==h)
                {
                    printf("%c",symbol);
                }
                else if (j==1 || j==w)
                {
                    printf("%c",symbol);
                }
                else
                {
                    printf(" ");
                }

            }
            printf("\n");
        }
    }
    return 0;
}
