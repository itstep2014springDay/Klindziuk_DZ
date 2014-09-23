#include <iostream>
#include <stdio.h>

using namespace std;

typedef char Data;
struct Node
{
    Data datum;
    Node *link;
};

void push(Node **top, Data dt)
{
    Node *p=NULL;
    p=new Node;
    p->datum=dt;
    p->link=*top;
    *top=p;
}

void pop(Node **top)
{
    Node *p=*top;
    if (p)
    {
        *top=p->link;
        p->datum=0;
        p->link=NULL;
        delete p;
        p=NULL;
    }
}

Data onTop(Node *top)
{
    if (!top)
        return -1;
    return top->datum;
}

bool isEmpty(Node *top)
{
    return top==NULL;
}

int main()
{
    unsigned char current;
    bool noError=false;
    Node *p=NULL;
    p=new Node;
    printf("Enter code\n");
    do
    {
        current=getchar();
        if (current=='(' && onTop(p)==-1)
            push(&p, current);
        if (current==')' && onTop(p)=='(')
            pop(&p);







    }
    while (current!='\n');
    if (noError)
        printf("No errors");
    else
        printf("Error!");
    delete p;
    return 0;
}
