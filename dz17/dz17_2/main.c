// Simple brainfuck
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n=1024;
    unsigned char memory[1024],current;
    int top=0;
    for (int i=0; i<n; ++i)
        memory[i]=0;
    printf("Enter code\n");
    do
    {
        current=getchar();
        switch (current)
        {
        case '+':
            ++memory[top];
            break;
        case '-':
            --memory[top];
            break;
        case '>':
            ++top;
            break;
        case '<':
            --top;
            break;
        case '.':
            putchar(memory[top]);
            break;
        }
    }
    while (current!=';');
    return 0;
}
