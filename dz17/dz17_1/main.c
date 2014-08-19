// Обратная польская запись
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double stack[100],a,b;
    int top,exit;
    char current;
    printf("Enter an expression\n");
    top=-1;
    exit=0;
    do
    {
        //scanf("%c",&current);
        current=getchar();
        switch (current)
        {
        case '0':
            stack[++top]=0;
            break;
        case '1':
            stack[++top]=1;
            break;
        case '2':
            stack[++top]=2;
            break;
        case '3':
            stack[++top]=3;
            break;
        case '4':
            stack[++top]=4;
            break;
        case '5':
            stack[++top]=5;
            break;
        case '6':
            stack[++top]=6;
            break;
        case '7':
            stack[++top]=7;
            break;
        case '8':
            stack[++top]=8;
            break;
        case '9':
            stack[++top]=9;
            break;
        case '+':
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a+b;
            break;
        case '-':
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a-b;
            break;
        case '*':
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a*b;
            break;
        case '/':
            b=stack[top--];
            a=stack[top--];
            stack[++top]=a/b;
            break;
        case '=':
            exit=1;
            break;
        }
    }
    while (!exit);
    printf("%f",stack[top--]);
    return 0;
}
