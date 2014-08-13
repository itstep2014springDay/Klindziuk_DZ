#include <stdio.h>
#include <stdlib.h>
#include "../mylib/arrayext.h"

int main()
{
    const int n=10;
    int a[10],temp[n];
    generateArray(a,n,0,20);

    printf("\nSelection sort\n");
    for(int i=0; i<10; ++i)
        temp[i]=a[i];
    outputArray(temp,n);
    sortSelectionArray(temp,n);
    outputArray(temp,n);

    printf("\nBubble sort\n");
    for(int i=0; i<10; ++i)
        temp[i]=a[i];
    outputArray(temp,n);
    sortBubbleArray(temp,n);
    outputArray(temp,n);

    printf("\nInsertion sort\n");
    for(int i=0; i<10; ++i)
        temp[i]=a[i];
    outputArray(temp,n);
    sortInsertionArray(temp,n);
    outputArray(temp,n);

    return 0;
}
