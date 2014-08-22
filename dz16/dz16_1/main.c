#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mylib/arrayext.h"

int main()
{
    srand(time(NULL));
    const int n=15;
    int a[n],temp[n];

    generateArray(a,n,0,20);

    printf("\n1. Selection sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortSelectionArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    printf("\n2. Bubble sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortBubbleArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    printf("\n3. Insertion sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortInsertionArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    printf("\n4. Merge sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortMergeArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    printf("\n5. Heap sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortHeapArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    printf("\n6. Quick sort\n");
    printf("Source array:\n");
    copyArrayAinB(a,temp,n);
    outputArray(temp,n);
    sortQuickArray(temp,n);
    printf("Sorted array:\n");
    outputArray(temp,n);

    return 0;
}
