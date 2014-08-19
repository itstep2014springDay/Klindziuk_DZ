// Brainfuck
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n=1024;
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
    /*
        printf("\n");
        for (i=0; i<size;++i)
            printf("%c",programm[i]);
    */
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
            ++i;
            break;
        case '[':
            if (memory[head]!='0')
            {
                ++head;
                ++i;
            }
            else // не получается прикрутить в этот else cтек
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
                    }
                }
                while (top!=oldTop);
                i=stack[top]+1;
            }
            break;
        case ']':
            if (memory[head]='0')
            {
                ++head;
                ++i;
            }
            else
            {
                // и в этот тоже
                i=stack[top]+1;
            }
            break;
        }
    }
    while (i<sizeProg);

    return 0;
}
