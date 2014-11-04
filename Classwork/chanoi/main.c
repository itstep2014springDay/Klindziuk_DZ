#include <stdio.h>
#include <stdlib.h>

void chanoi(char a,char b,char c,int n);

int main()
{
    int n;
    printf("Enter N\n");
    scanf("%d",&n);
    chanoi('A','B','C',n);
    return 0;
}

void chanoi(char a,char b,char c,int n)
{
    if (n==1)
    {
        printf("%c -> %c\n",a,b);
    }
    else
    {
        chanoi(a,c,b,n-1);
        printf("%c -> %c\n",a,b);
        chanoi(c,b,a,n-1);
    }
}
