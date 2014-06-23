// Простой калькулятор
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char znak;
    printf("A=");
    scanf("%d",&a);
    printf("Znak=");
    scanf("%s",&znak);
    printf("B=");
    scanf("%d",&b);
    switch (znak)
    {
    case '+':
        printf("%d",a+b);
        break;
    case '-':
        printf("%d",a-b);
        break;
    case '*':
        printf("%d",a*b);
        break;
    case '/':
        printf("%f",(double)a/b);
        break;
    }
    return 0;
}
