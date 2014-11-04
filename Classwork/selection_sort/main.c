#include <stdio.h>
#include <stdlib.h>

void sortSelectionArray(int array[],int size)
{
    int indexOfMax,max,temp;
    for (int i=1; i<size; ++i)
    {
        indexOfMax=0;
        max=array[0];
        for (int j=1; j<=size-i; ++j)
        {
            if (max<array[j])
            {
                max=array[j];
                indexOfMax=j;
            }
        }
        temp=array[size-i];
        array[size-i]=array[indexOfMax];
        array[indexOfMax]=temp;
    }
}

void sortBubbleArray(int array[],int size)
{
    for (int i=0; i<size-1; ++i)
    {
        for (int j=0; j<size-i-1; ++j)
        {
            if (array[j]>array[j+1])
            {
                int temp;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

void outputArray(int array[],int size)
{
    printf("Output array of %d elements\n",size);
    for (int i=0; i<size; ++i)
        printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    const int n=7;
    int a[7]= {10,1,3,12,-8,15,27};
    outputArray(a,n);
    sortBubbleArray(a,n);
    outputArray(a,n);
    return 0;
}
