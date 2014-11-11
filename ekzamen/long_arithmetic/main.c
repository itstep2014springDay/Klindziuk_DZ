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
    //fprintf(outputFile,"\n");
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

void multiLongToShort(const myLongType a, const int shortNumber, myLongType c)
{
    memset(c,0,sizeof(myLongType));
    if (shortNumber==0)
        ++c[0];
    else
    {
        for(int i=1; i<=a[0]; ++i)
        {
            c[i+1]=(a[i]*shortNumber+c[i])/BASE;
            c[i]=(a[i]*shortNumber+c[i])%BASE;
        }
        if (c[a[0]+1]>0)
            c[0]=a[0]+1;
        else
            c[0]=a[0];
    }
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

int findBin(myLongType remainder,const myLongType b,int shift)
{
    myLongType c;
    int up=BASE,down=0;
    while (up-1>down)
    {
        multiLongToShort(b,(up+down)/2,c);
        switch (moreAB(remainder,c,shift))
        {
        case 0:
            down=(up+down)/2;
            break;
        case 1:
            up=(up+down)/2;
            break;
        case 2:
            up=(up+down)/2;
            down=up;
            break;
        }
    }
    multiLongToShort(b,(up+down)/2,c);
    if(moreAB(remainder,c,0)==0)
    {
        myLongType temp;
        memset(temp,0,sizeof(myLongType));
        subLong(remainder,c,shift,temp);
        for (int i=0; i<=remainder[0]; ++i)
            remainder[i]=temp[i];
    }
    else
    {
        myLongType temp;
        memset(temp,0,sizeof(myLongType));
        subLong(c,remainder,shift,temp);
        for (int i=0; i<=c[0]; ++i)
            c[i]=temp[i];
        memset(remainder,0,sizeof(myLongType));
        for (int i=0; i<=c[0]; ++i)
            remainder[i]=c[i];
    }
    return (up+down)/2;
}

void makeDel(const myLongType a, const myLongType b, myLongType quotient, myLongType remainder)
{
    //memset(quotient,0,sizeof(myLongType));
    //memset(remainder,0,sizeof(myLongType));
    for (int i=0; i<=a[0]; ++i)
        remainder[i]=a[i];
    int shift;
    shift=a[0]-b[0];
    if(moreAB(a,b,shift)==1)
        --shift;
    quotient[0]=shift+1;
    while (shift>=0)
    {
        quotient[shift+1]=findBin(remainder,b,shift);
        --shift;
    }
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
    myLongType a,b,c,quotient,remainder;
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
        fprintf(outputFile,"\n");
        fprintf(outputFile,"B= ");
        writeLong(outputFile,b);
        fprintf(outputFile,"\n");

        fprintf(outputFile,"A+B= ");
        sumLong(a,b,c);
        writeLong(outputFile,c);
        fprintf(outputFile,"\n");

        fprintf(outputFile,"A-B= ");
        if (moreAB(a,b,0)) // костыль для вывода отицательных чисел
        {
            subLong(b,a,0,c);
            fprintf(outputFile,"-");
        }
        else
            subLong(a,b,0,c);
        writeLong(outputFile,c);
        fprintf(outputFile,"\n");

        fprintf(outputFile,"A*B= ");
        multiLong(a,b,c);
        writeLong(outputFile,c);
        fprintf(outputFile,"\n");

        fprintf(outputFile,"A/B= ");
        divLongToLong(a,b,quotient,remainder);
        writeLong(outputFile,quotient);
        fprintf(outputFile," : ");
        writeLong(outputFile,remainder);
        fprintf(outputFile,"\n");

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
        fprintf(stdout,"\n");

        fprintf(stdout,"A-B= ");
        if (moreAB(a,b,0)) // костыль для вывода отицательных чисел
        {
            subLong(b,a,0,c);
            fprintf(stdout,"-");
        }
        else
            subLong(a,b,0,c);
        writeLong(stdout,c);
        fprintf(stdout,"\n");

        fprintf(stdout,"A*B= ");
        multiLong(a,b,c);
        writeLong(stdout,c);
        fprintf(stdout,"\n");

        fprintf(stdout,"A/B= ");
        divLongToLong(a,b,quotient,remainder);
        writeLong(stdout,quotient);
        fprintf(stdout," : ");
        writeLong(stdout,remainder);
        fprintf(stdout,"\n");
    }
    return 0;
}
