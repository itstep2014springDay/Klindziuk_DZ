#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

void intToChar(int number, char *str)
{
    int i=0,symbol,temp=number,n=0;
    while (temp>0)
    {
        temp/=10;
        ++n;
    }
    for (i=n-1; i>=0;--i)
    {
        symbol=number%10;
        str[i]=symbol+'0';
        number/=10;
    }
    str[n]='\0';
}

void myPrint(char *str, int n)
{
    write(1,str,n);
}

void myprintf(char *format, ...)
{
    va_list argumentPointer;
    va_start(argumentPointer,format);

    int number=va_arg(argumentPointer,int);



    va_end(argumentPointer);

}

int main()
{
    int number=123;
    char str[10];
    intToChar(number,str);
    myPrint(str,strlen(str));
    return 0;
}
