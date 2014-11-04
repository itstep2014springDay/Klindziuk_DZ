#include <stdio.h>
#include <stdlib.h>

typedef  struct _Date
{
    int day;
    int month;
    int year;
} Date;

Date input()
{
    Date xxx;
    printf("Enter day: ");
    scanf("%d",&xxx.day);
    printf("Enter month: ");
    scanf("%d",&xxx.month);
    printf("Enter year: ");
    scanf("%d",&xxx.year);
    return xxx;
}

void output(Date xxx)
{
    printf("%d.%d.%d",xxx.day,xxx.month,xxx.year);
}

int convert(Date xxx)
{
    int days=0,month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i=0; i<xxx.year;++i)
        if (xxx.year%400==0 && xxx.year%100!=0 && xxx.year%4==0)
            days+=xxx.year*366;
        else
            days+=xxx.year*365;
    days+=xxx.month*month[xxx.month+1];
    if (xxx.year%400==0 && xxx.year%100!=0 && xxx.year%4==0 && xxx.month>2)
        ++days;
    days+=xxx.day;
    return days;
}

Date reverceConvert(int days)
{
    int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    Date xxx;


    for (int i=0; i<xxx.year;++i)
        if (xxx.year%400==0 && xxx.year%100!=0 && xxx.year%4==0)
            days+=xxx.year*366;
        else
            days+=xxx.year*365;
    days+=xxx.month*month[xxx.month+1];
    if (xxx.year%400==0 && xxx.year%100!=0 && xxx.year%4==0 && xxx.month>2)
        ++days;
    days+=xxx.day;



    return xxx;
}


int main()
{
    Date a;
    a=input();
    output(a);
    printf("\n");
    printf("Hello world!\n");
    return 0;
}
