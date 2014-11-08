#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXDIGITS 1000
#define BASE 10000

typedef int myLongType[MAXDIGITS];

void readLong(myLongType a)
{
    memset(a,0,sizeof(myLongType));
    char current=getchar();
    while (current!='\n')
    {
        for (int i=a[0]; i>=1; --i)
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

void writeLong(const myLongType a)
{
    //char ls[10],s[10];
    char ls[(int) log10(MAXDIGITS)],s[(int) log10(MAXDIGITS)];
    sprintf(ls,"%d",BASE/10);
    printf("%d",a[a[0]]);
    for(int i=a[0]-1; i>=1; --i)
    {
        sprintf(s,"%d",a[i]);
        while (strlen(s)<strlen(ls)) // а в паскале тут всего одна строка  s:='0'+s;
        {
            char tmpStr[10]="0";
            strcat(tmpStr,s);
            strcpy(s,tmpStr);
        }
        printf("%s",s);
    }
    printf("\n");
}

void sumLong(const myLongType a, const myLongType b, myLongType c)
{
    memset(c,0,sizeof(myLongType));
    int k;
    if (a[0]>b[0])
        k=a[0];
    else
        k=b[0];
    for (int i=1; i<=k; ++i)
    {
        c[i+1]=(c[i]+a[i]+b[i])/BASE;
        c[i]=(c[i]+a[i]+b[i])%BASE;
    }
    if (c[k+1]==0)
        c[0]=k;
    else
        c[0]=k+1;
}

int main()
{
    myLongType a,b,c;
    printf("A= ");
    readLong(a);
    printf("B= ");
    readLong(b);

    sumLong(a,b,c);
    printf("C= ");
    writeLong(c);

    return 0;
}
