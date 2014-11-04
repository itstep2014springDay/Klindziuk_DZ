#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>

void myprintf(char *format, ...)
{
    va_list argumentPointer;
    va_start(argumentPointer,format);

    int number=va_arg(argumentPointer,int);



    va_end(argumentPointer);

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
