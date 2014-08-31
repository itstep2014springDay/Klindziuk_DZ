// Brainfuck
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n=3000;
    unsigned char memory[n],programm[n],current;
    int head=0,top=-1,oldTop,i,sizeProg,stack[n];
    for (i=0; i<n; ++i)
        memory[i]=0;
    printf("Enter code\n");
    i=0;
    do
    {
        programm[i]=getchar();
        i++;
    }
    while (programm[i-1]!='\n');
    sizeProg=i-1;
    i=0;
    do
    {
        current=programm[i];
        switch (current)
        {
        case '+':
            ++memory[head];
            ++i;
            break;
        case '-':
            --memory[head];
            ++i;
            break;
        case '>':
            ++head;
            ++i;
            break;
        case '<':
            --head;
            ++i;
            break;
        case '.':
            putchar(memory[head]);
            ++i;
            break;
        case ',':
            memory[head]=getchar();
            getchar();
            ++i;
            break;
        case '[':
            if (memory[head]!=0)
            {
                stack[++top]=i;
                ++i;
            }
            else
            {
                oldTop=top;
                do
                {
                    current=programm[i];
                    switch (current)
                    {
                    case '[':
                        stack[++top]=i;
                        ++i;
                        break;
                    case ']':
                        --top;
                        ++i;
                        break;
                    default:
                        ++i;
                    }
                }
                while (top!=oldTop);
            }
            break;
        case ']':
            if (memory[head]==0)
            {
                ++i;
                --top;
            }
            else
            {
                i=stack[top--];
            }
            break;
        }
    }
    while (i<sizeProg);

    return 0;
}
