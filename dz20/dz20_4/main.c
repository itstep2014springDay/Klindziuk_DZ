// qsort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpInt(const void *a, const void *b) //как это работает???
{
    return *((int *)a)-*((int *)b);
}

int cmpIntReverce(const void *a, const void *b)
{
    return *((int *)b)-*((int *)a);
}

void outputArray(int *array, int sizeArray)
{
    printf("Output array of %d elements\n",sizeArray);
    for (int i=0; i<sizeArray; ++i)
        printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    int n=10;
    printf("Enter N:\n");
    scanf("%d",&n);
    int *array=NULL;
    array=(int *)malloc(n*sizeof(int));
    srand(time(NULL));
    for (int i=0; i<n; ++i)
        array[i]=rand()%100;
    outputArray(array,n);
    printf("\nSort\n");
    qsort(array,n,sizeof(int),cmpInt);
    outputArray(array,n);
    printf("\nReverce sort\n");
    qsort(array,n,sizeof(int),cmpIntReverce);
    outputArray(array,n);
    free(array);
    array=NULL;
    return 0;
}
