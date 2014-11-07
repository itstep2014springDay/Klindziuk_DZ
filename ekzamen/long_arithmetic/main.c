#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIGITS 1000
#define BASE 10000

typedef int myLongType[MAXDIGITS];

void readLong(myLongType a)
{
    memset(a,0,sizeof(myLongType));
    char current=getchar();
    while (current!='\n')
    {
        for (int i=a[0];i>=1;--i)
        {
            a[i+1]=a[i+1]+a[i]*10/BASE;
            a[i]=a[i]*10%BASE;
        }
        a[1]=a[1]+current-'0';
        if (a[a[0]+1]>0)
            ++a[0];
        current=getchar();
    }
}


int main()
{
    myLongType a,b;
    readLong(a);

    printf("Hello world!\n");
    return 0;
}
