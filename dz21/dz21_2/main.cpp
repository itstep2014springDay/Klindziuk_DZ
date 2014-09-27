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
    bool error=false;
    Node *top=NULL;
    printf("Enter code\n");
    do
    {
        current=getchar();
        switch (current)
        {
        case '(':
            push(&top, current);
            break;
        case ')':
            if (onTop(top)=='(')
                pop(&top);
            else
                error=true;
            break;
        case '[':
            push(&top, current);
            break;
        case ']':
            if (onTop(top)=='[')
                pop(&top);
            else
                error=true;
            break;
        case '{':
            push(&top, current);
            break;
        case '}':
            if (onTop(top)=='{')
                pop(&top);
            else
                error=true;
            break;
        }
        if (error)
            break;
    }
    while (current!='\n');
    if (!isEmpty(top))
        error=true;
    if (error)
        printf("Error!");
    else
        printf("No errors");
    delete top;
    return 0;
}
