#include <stdio.h>
#include <stdlib.h>
#include "../mylib/mathext.h"

int main()
{
    const int n=5;
    int a[n],x,index;
    inputArray(a,n);
    outputArray(a,n);
    printf("Enter X\n");
    scanf("%d",&x);
    index=searchInArray(a,n,x);
    if (x==-1)
        printf("Element %d not found",x);
    else
        printf("Index element %d is: %d",x,index+1);
    return 0;
}
