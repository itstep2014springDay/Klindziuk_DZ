#include <stdio.h>
#include <stdlib.h>
#include "../mylib/arrayext.h"

void sortMergeArray(int ar[],int l,int r)
{
    if (l<r)
    {
        sortMergeArray(ar,l,(r+l)/2);
        sortMergeArray(ar,(r+l)/2+1,r);
        int const sizeMax=1024;
       // static int br[sizeMax],cr[sizeMax];
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
        //какой оставшийся массив???


    }
}


int main()
{
    const int n=10;
    int a[n],temp[n];
    generateArray(a,n,0,20);
    /*
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
    */
    printf("\nSelection sort\n");
    // for(int i=0; i<10; ++i)
    //    temp[i]=a[i];
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
    outputArray(temp,n);
    sortMergeArray(temp,0,n-1);
    outputArray(temp,n);


    return 0;
}
