#include <stdio.h>
#include <stdlib.h>
#include "../mylib/arrayext.h"

int main()
{
    const int n=10;
    int a[n],temp[n];
    /*
        temp[0]=5;
        temp[1]=2;
        temp[2]=7;
        temp[3]=9;
        temp[4]=3;
        temp[5]=2;
        temp[6]=1;
        temp[7]=8;
        temp[8]=6;
        temp[9]=4;
    */
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

    printf("\nMerge sort\n");
    for(int i=0; i<10; ++i)
        temp[i]=a[i];
    outputArray(temp,n);
    sortMergeArray(temp,0,n-1);
    outputArray(temp,n);


    return 0;
}
