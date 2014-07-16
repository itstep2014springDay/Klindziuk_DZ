// Вычисление НОД и НОК с использованием своей библиотеки функций
#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

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
