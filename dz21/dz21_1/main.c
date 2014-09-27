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
    printf("Enter date\n");
    printf("Enter day: ");
    /* scanf("%d",&xxx.day);
     printf("Enter month: ");
     scanf("%d",&xxx.month);
     printf("Enter year: ");
     scanf("%d",&xxx.year);
     */
    xxx.day=27;
    xxx.month=9;
    xxx.year=2014;
    return xxx;
}

void output(Date xxx)
{
    printf("%d.%d.%d",xxx.day,xxx.month,xxx.year);
}

int convertDateToDays(Date xxx)
{
    int days=0,year=xxx.year-1,month[12]= {0,31,59,90,120,151,181,212,243,270,304,334};
    days=146097*year/400;
    year%=400;
    days+=36524*year/100;
    year%=100;
    days+=1461*year/4;
    days+=month[xxx.month-1];
    days+=xxx.day;
    if (xxx.month>2 && (xxx.year%400==0 || (xxx.year%100!=0 && xxx.year%4==0)))
        ++days;
    return days;
}

Date convertDaysToDate(int days)
{
    int year=1,month[12]= {0,31,59,90,120,151,181,212,243,270,304,334};
 /*
        year=400*days/146097;
        days%=400;
        year+=100*days/36524;
        days%=100;
        year+=4*days/1461;
        */
    while (days>365)
    {
        if (year%400==0 || (year%100!=0 && year%4==0))
            days-=366;
        else
            days-=365;
        ++year;
    }
// что-то не получается обратно год из дней посчитать
    printf("\ny=%d",year);
    printf("\nd=%d",days);

    Date xxx;
    xxx.year=year;
    for (int i=0;i<12;++i)
        if (days<month[i])
        {
            xxx.month=i;
            days-=month[i-1];
            break;
        }
    xxx.day=days;
    return xxx;
}


int main()
{
    Date a;
    a=input();
    output(a);
    int days;
    days=convertDateToDays(a);
    printf("\n");
    printf("Days= %d",days);
    a=convertDaysToDate(days);
    printf("\n");
    output(a);
    return 0;
}
