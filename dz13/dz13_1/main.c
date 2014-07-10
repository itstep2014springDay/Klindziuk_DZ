// Функции НОД и НОК
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    int a,b;
    printf("A=");
    scanf("%d",&a);
    printf("B=");
    scanf("%d",&b);
    printf("GCD=%d\nLCM=%d",gcd(a,b),lcm(a,b));
    return 0;
}

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
