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
