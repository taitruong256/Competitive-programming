#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->next=NULL;
    temp->data=x;
    return temp;
}

node *addNode(node *last, int x)
{
    node *temp = createNode(x);
    last->next=temp;
    return temp;
}

void printList(node *first)
{
    while (first!=NULL)
    {
        cout<<first->data<<" ";
        first=first->next;
    }
    cout<<endl;
}

node *insertNode(node *first, int k, int x)
{
    if (k==0)
    {
        node *temp = createNode(x);
        temp->next=first;
        return temp;
    }
    node *p=first;
    for (int i=0; i<k-1; i++) p=p->next;
    node *temp=createNode(x);
    temp->next=p->next;
    p->next=temp;
    return first;
}

int main()
{
    system("cls");
    int n, x, k; cin>>n;
    cin>>x;
    node *first = createNode(x);
    node *last=first;
    for (int i=1; i<n; i++) 
    {
        cin>>x;
        last=addNode(last, x);
    }
    cin>>x>>k;
    first=insertNode(first, x, k);
    printList(first);
    return 0;
}