#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXDIGITS 1000
#define BASE 10000

typedef int myLongType[MAXDIGITS];

void readLong(FILE *inputFile, myLongType a)
{
    memset(a,0,sizeof(myLongType));
    char current=fgetc(inputFile);
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
        current=fgetc(inputFile);
    }
}

void writeLong(FILE *outputFile, const myLongType a)
{
    //char ls[10],s[10];
    char ls[(int) log10(MAXDIGITS)],s[(int) log10(MAXDIGITS)];
    sprintf(ls,"%d",BASE/10);  // itoa() почему-то не работал
    fprintf(outputFile,"%d",a[a[0]]);
    for(int i=a[0]-1; i>=1; --i)
    {
        sprintf(s,"%d",a[i]);
        while (strlen(s)<strlen(ls)) // а в паскале тут всего одна строка  s:='0'+s;
        {
            char tmpStr[10]="0";
            strcat(tmpStr,s);
            strcpy(s,tmpStr);
        }
        fprintf(outputFile,"%s",s);
    }
    fprintf(outputFile,"\n");
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

void multiLong(const myLongType a, const myLongType b, myLongType c)
{
    memset(c,0,sizeof(myLongType));
    for (int i=1; i<=a[0]; ++i)
        for (int j=1; j<=b[0]; ++j)
        {
            int dv;
            dv=(a[i]*b[j]+c[i+j-1]);
            c[i+j]=c[i+j]+(dv/BASE);
            c[i+j-1]=dv%BASE;
        }
    c[0]=a[0]+b[0];
    while (c[0]>1 && c[c[0]]==0)
        --c[0];
}

int moreAB(const myLongType a, const myLongType b, int shift)
{
    int more;
    if (a[0]>b[0]+shift)
        more=0;
    else if (a[0]<b[0]+shift)
        more=1;
    else
    {
        int i=a[0];
        while (i>shift && a[i]==b[i-shift])
            --i;
        if (i==shift)
        {
            more=0;
            for (i=1; i<=shift; ++i)
                if (a[i]>0)
                    return more;
            more=2;
        }
        else
            more=(int) (a[i]<b[i-shift]);
    }
    return more;
}

void subLong(const myLongType a, const myLongType b,int sp, myLongType c)
{
    memset(c,0,sizeof(myLongType));
    for (int i=0; i<=a[0]; ++i)
        c[i]=a[i];
    for (int i=1; i<=b[0]; ++i)
    {
        c[i+sp]=c[i+sp]-b[i];
        int j=i;
        while (c[j+sp]<0 && j<=c[0])
        {
            c[j+sp]=c[j+sp]+BASE;
            --c[j+sp+1];
            ++j;
        }
    }
    int i=c[0];
    while (i>1 && c[i]==0)
        --i;
    c[0]=i;
}

void swapAB(myLongType a, myLongType b)
{
    myLongType temp;
    memset(temp,0,sizeof(myLongType));
    for (int i=0; i<=a[0]; ++i)
        temp[i]=a[i];
    memset(a,0,sizeof(myLongType));
    for (int i=0; i<=b[0]; ++i)
        a[i]=b[i];
    memset(b,0,sizeof(myLongType));
    for (int i=0; i<=temp[0]; ++i)
        b[i]=temp[i];
}

void makeDel(const myLongType a, const myLongType b, myLongType quotient, myLongType remainder)
{

}

void divLongToLong(const myLongType a, const myLongType b, myLongType quotient, myLongType remainder)
{
    memset(quotient,0,sizeof(myLongType));
    quotient[0]=1;
    memset(remainder,0,sizeof(myLongType));
    remainder[0]=1;
    switch (moreAB(a,b,0))
    {
    case 0:
        makeDel(a,b,quotient,remainder);
        break;
    case 1:
        for (int i=0; i<=a[0]; ++i)
            remainder[i]=a[i];
        break;
    case 2:
        quotient[1]=1;
        break;
    }
}

int main()
{
    myLongType a,b,c;
    printf("Choise mode\nPress '1' - work with console\nPress '2' - work with files\nMode: ");
    int mode;
    scanf("%d",&mode);
    fflush(stdin);
    //char mode=gets();
    if (mode==2) // режим работы с файлами
    {
        FILE *inputFile,*outputFile;
        inputFile=fopen("input.txt","r");
        readLong(inputFile,a);
        readLong(inputFile,b);
        fclose(inputFile);
        outputFile=fopen("output.txt","w");

        fprintf(outputFile,"A= ");
        writeLong(outputFile,a);
        fprintf(outputFile,"B= ");
        writeLong(outputFile,b);

        fprintf(outputFile,"A+B= ");
        sumLong(a,b,c);
        writeLong(outputFile,c);

        fprintf(outputFile,"A-B= ");
        if (moreAB(a,b,0)) // костыль для вывода отицательных чисел
        {
            swapAB(a,b);
            fprintf(outputFile,"-");
        }
        subLong(a,b,0,c);
        writeLong(outputFile,c);

        fprintf(outputFile,"A*B= ");
        multiLong(a,b,c);
        writeLong(outputFile,c);

        fclose(outputFile);
        fprintf(stdout,"Done. See \"output.txt\"\n");
    }
    else // режим работы с консолью в другом случае
    {
        fprintf(stdout,"A= ");
        readLong(stdin,a);
        fprintf(stdout,"B= ");
        readLong(stdin,b);

        fprintf(stdout,"A+B= ");
        sumLong(a,b,c);
        writeLong(stdout,c);

        fprintf(stdout,"A-B= ");
        if (moreAB(a,b,0)) // костыль для вывода отицательных чисел
        {
            swapAB(a,b);
            fprintf(stdout,"-");
        }
        subLong(a,b,0,c);
        writeLong(stdout,c);

        fprintf(stdout,"A*B= ");
        multiLong(a,b,c);
        writeLong(stdout,c);
    }
    return 0;
}
