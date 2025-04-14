#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *previous;
};

struct nodeList
{
    node *first;
    node *last;
};

nodeList *createList(int x)
{
    nodeList *pos = new nodeList;
    pos->first=new node;
    pos->first->data=x;
    pos->first->previous=NULL;
    pos->first->next=NULL;
    pos->last=pos->first;
    return pos;
}

nodeList *addHead(nodeList *l, int x)
{
    node * temp=new node;
    temp->data=x;
    temp->previous=NULL;
    temp->next=l->first;
    l->first->previous=temp;
    l->first=temp;
    return l;
}

nodeList *addTail(nodeList *l, int x)
{
    node * temp=new node;
    temp->data=x;
    temp->next=NULL;
    temp->previous=l->last;
    l->last->next=temp;
    l->last=temp;
    return l;
}

nodeList *addAt(nodeList *l, int k, int x)
{
    node *pos=new node;
    pos=l->first;
    for (int i=0; i<k-1; i++) pos=pos->next;
    node *temp = new node;
    temp->data=x;
    temp->next=pos->next;
    temp->previous=pos;
    pos->next->previous=temp;
    pos->next=temp;
    return l;
}

void printList(nodeList *l)
{
    node *pos=new node;
    pos=l->first;
    while (pos!=NULL)
    {
        cout<<pos->data<<" ";
        pos=pos->next;
    }
}

nodeList *deleteHead(nodeList *l)
{
    node *temp=l->first;
    node *pos =temp->next;
    pos->previous=NULL;
    l->first=pos;
    delete(temp);
    return l;
}

nodeList *deleteTail(nodeList *l)
{
    node *temp=l->last;
    node *pos=temp->previous;
    pos->next=NULL;
    l->last=pos;
    delete(temp);
    return l;
}

nodeList *deleteAt(nodeList *l, int k)
{
    node *pos=l->first;
    for (int i=0; i<k-1; i++) pos=pos->next;
    node *temp=pos->next;
    pos->next=temp->next;
    temp->next->previous=pos;
    delete(temp);
    return l;
}

int main()
{
    system("cls");
    int n, k, x; cin>>n;
    cin>>x;
    nodeList *l = createList(x);
    for (int i=1; i<n; i++)
    {
        cin>>x;
        l=addTail(l, x);
    }
    cin>>k;
    if (k==0) deleteHead(l);
    else if (k==n-1) deleteTail(l);
    else deleteAt(l, k);
    printList(l);
    return 0;
}