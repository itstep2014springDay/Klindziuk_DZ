// Сложный калькулятор
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,rez,exit;
    char znak;
    printf("x=");
    scanf("%d",&x);
    rez=x;
    exit=1;
    do
    {
        printf("Znak=");
        scanf("%s",&znak);
        switch (znak)
        {
        case '+':
            printf("x=");
            scanf("%d",&x);
            rez=rez+x;
            break;
        case '-':
            printf("x=");
            scanf("%d",&x);
            rez=rez-x;
            break;
        case '*':
            printf("x=");
            scanf("%d",&x);
            rez=rez*x;
            break;
        case '/':
            printf("x=");
            scanf("%d",&x);
            rez=rez/x;
            break;
        case '=':
            printf("Rez= %d",rez);
            getch();
            system("cls");
            printf("x=");
            scanf("%d",&x);
            rez=x;
            break;
        case 'c':
            system("cls");
            printf("x=");
            scanf("%d",&x);
            rez=x;
            break;
         case 'e':
            exit=0;
            break;
        }
    }
    while (exit);
    return 0;
}
