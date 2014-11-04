#include <stdio.h>
#include <stdlib.h>

void infinity(int n);

int main()
{
    int choise;
    printf("Enter 0 or 1\n");
    scanf("%d",&choise);
    if (choise)
    {
        while(1) {}
    }
    else
    {
        infinity(0);
    }
    return 0;
}

void infinity(int n)
{
    int mas[100000];
    printf("%d\n",n);
    infinity(n+1);
}
