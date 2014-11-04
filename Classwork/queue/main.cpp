#include <iostream>
#include <stdio.h>

using namespace std;

typedef int Data;
struct Node
{
    Data datum;
    Node *link;
};

void enqueue(Node *&head, Node *&tail, int value)
{
    Node *p=nullptr;
    p=new Node;
    p->datum=value;
    p->link=nullptr;
    if (head==nullptr && tail==nullptr)
    {
        head=p;
    }
    else
    {
        tail->link=p;
    }
    tail=p;
}

int dequeue(Node *&head, Node *&tail)
{
    if(head==nullptr)
        return -1;
    Node *p=head;
    int result;
    result=p->datum;
    if (head==tail)
    {
        tail=nullptr;
    }
    head=p->link;
    delete p;
    return result;

}

int main()
{
    Node *head=nullptr, *tail=nullptr;
    enqueue(head,tail, 10);
    enqueue(head,tail, 5);
    enqueue(head,tail, 3);
    printf("%d\n",dequeue(head,tail));
    printf("%d\n",dequeue(head,tail));
    printf("%d\n",dequeue(head,tail));
    printf("%d\n",dequeue(head,tail));
    return 0;
}
