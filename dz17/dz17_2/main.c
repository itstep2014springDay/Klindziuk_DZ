// Simple brainfuck
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n=1024;
    unsigned char memory[n],current;
    int head=0;
    for (int i=0; i<n; ++i)
        memory[i]=0;
    printf("Enter code\n");
    do
    {
        current=getchar();
        switch (current)
        {
        case '+':
            ++memory[head];
            break;
        case '-':
            --memory[head];
            break;
        case '>':
            ++head;
            break;
        case '<':
            --head;
            break;
        case '.':
            putchar(memory[head]);
            break;
        }
    }
    while (current!=';');
    return 0;
}
