#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

int main()
{
    const int n=5;
    int a[n],min,max;
    generateArray(a,n,1,10);
    outputArray(a,n);
    min=searchMinInArray(a,n);
    max=searchMaxInArray(a,n);
    printf("Min: %d\nMax: %d",min,max);
    return 0;
}
