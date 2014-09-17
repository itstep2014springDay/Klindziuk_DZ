// Стек
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void push(int *stack, int size, int *top, int datum)
{
    assert(*top<size-1);
    stack[++(*top)]=datum;
}

void pop(int top)
{
   top--;
}

int onTop(int *stack, int top)
{
if (top<0)
    return -1;
   return stack[top];
}

int  isEmpty(int top)
{
   return top=-1;
}

int main()
{
    int *stack=NULL,top=-1,size=100,datum;
    stack=(int*)malloc(size*sizeof(int*));



    free(stack);
    stack=NULL;
    return 0;
}
