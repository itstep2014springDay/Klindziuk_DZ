// Стек
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void push(int *stack, int size, int *top, int datum)
{
    assert(*top<size-1);
    stack[++(*top)]=datum;
}

void pop(int *stack, int *top, int datum)
{
   datum=stack[(*top)--];
}

void onTop(int *stack, int *top, int datum)
{
   datum=stack[(*top)];
}

void isEmpty(int *top)
{
   *top=-1;
}

int main()
{
    int *stack=NULL,*top,size=100,datum;
    stack=(int*)malloc(size*sizeof(int*));
    int start=-1;
    top=&start;


    free(stack);
    stack=NULL;
    return 0;
}
