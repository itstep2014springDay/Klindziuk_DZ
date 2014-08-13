#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mylib/mathext.h"

int gcd(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b)
            a=a%b;
        else
            b=b%a;
    }
    return (a+b);
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}

void convert36(int x, int b)
{
    int i,y,z,k;
    y=0;
    i=1;
    k=0;
    while (x>0)
    {
        z=x%b;
        y=z+y*b;
        i=i*b;
        x=x/b;
        ++k;        // счётчик цифр числа
    }
    while (k)
    {
        z=y%b;
        y=y/b;
        if (z>=10)
            printf("%c",z+55);
        else
            printf("%d",z);
        --k;
    }
}

void drawDice(int x)
{
    switch (x)
    {
    case 1:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c   %c\n",179,179);
        printf("%c * %c\n",179,179);
        printf("%c   %c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    case 2:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c*  %c\n",179,179);
        printf("%c   %c\n",179,179);
        printf("%c  *%c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    case 3:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c*  %c\n",179,179);
        printf("%c * %c\n",179,179);
        printf("%c  *%c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    case 4:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c* *%c\n",179,179);
        printf("%c   %c\n",179,179);
        printf("%c* *%c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    case 5:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c* *%c\n",179,179);
        printf("%c * %c\n",179,179);
        printf("%c* *%c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    case 6:
        printf("%c%c%c%c%c\n",218,196,196,196,191);
        printf("%c* *%c\n",179,179);
        printf("%c* *%c\n",179,179);
        printf("%c* *%c\n",179,179);
        printf("%c%c%c%c%c\n",192,196,196,196,217);
        break;
    default:
        printf("Error!\n");
    }
}

int myRandWiki(int x0)
{
    int x,a,c,m;
    a=4096;
    c=150889;
    m=714025;
    x=(a*x0+c)%m;
    return x;
}

int myRandOther(int x0)
{
    int x,a,c,m;
    a=5;
    c=1;
    m=4;
    x=(a*x0+c)%m;
    return x;
}

int primeNumber(int x) //bool
{
    if (x<=1)
        return 0;
    else
    {
        int flag=0;
        for (int i=2; i*i<=x; ++i)
        {
            if (x%i==0)
                ++flag;
        }
        if (flag==0)
            return 1;
        else
            return 0;
    }
}
