#include <stdio.h>
#include <stdlib.h>
#include "mathextended.h"

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
