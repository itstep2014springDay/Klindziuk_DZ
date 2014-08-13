#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mylib/arrayext.h"

void inputArray(int array[],int size)
{
    printf("Enter array of %d elements\n",size);
    for (int i=0; i<size; ++i)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&array[i]);
    }
}

void outputArray(int array[],int size)
{
    printf("Output array of %d elements\n",size);
    for (int i=0; i<size; ++i)
        printf("%d ",array[i]);
    printf("\n");
}

int searchInArray(const int array[],int size,int number)
{
    int index=-1;
    for (int i=0; i<size; ++i)
        if (number==array[i])
        {
            index=i;
            break;
        }
    return index;
}

void generateArray(int array[],int size, int min, int max)
{
    srand(time(NULL));
    for (int i=0; i<size; ++i)
        array[i]=rand()%(max+1)+min;
}

int searchMinInArray(int array[],int size)
{
    int min=array[0];
    for (int i=1; i<size; ++i)
        if (array[i]<min)
            min=array[i];
    return min;
}

int searchMaxInArray(int array[],int size)
{
    int max=array[0];
    for (int i=1; i<size; ++i)
        if (array[i]>max)
            max=array[i];
    return max;
}

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

void sortInsertionArray(int array[],int size)
{
    array[0];
    for (int i=0; i<size-1; ++i)
    {
        int j=i;
        while (array[j+1]<array[j] && j>=0)
        {
            int temp;
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            --j;
        }
    }
}

