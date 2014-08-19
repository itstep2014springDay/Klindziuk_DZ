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

void sortMergeArray(int ar[],int l,int r)
{
    if (l<r)
    {
        sortMergeArray(ar,l,(r+l)/2);
        sortMergeArray(ar,(r+l)/2+1,r);
        const int sizeMax=1024;
        //static int br[sizeMax],cr[sizeMax];  // всё равно не работает эта константа, в ".h" и в static
        static int br[1024],cr[1024];
        for (int i=l; i<=(r+l)/2; ++i)
            br[i]=ar[i];
        for (int i=(r+l)/2+1; i<=r; ++i)
            cr[i]=ar[i];
        int i=l,j=l,k=(r+l)/2+1;
        while (j<=(r+l)/2 && k<=r)
        {
            if (br[j]<cr[k])
            {
                ar[i]=br[j];
                ++j;
            }
            else
            {
                ar[i]=cr[k];
                ++k;
            }
            ++i;
        }
        while (j<=(r+l)/2)
        {
            ar[i]=br[j];
            ++j;
            ++i;
        }
        while (k<=r)
        {
            ar[i]=cr[k];
            ++k;
            ++i;
        }
    }
}

