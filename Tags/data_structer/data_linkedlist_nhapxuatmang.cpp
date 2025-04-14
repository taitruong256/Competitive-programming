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

node *addNode(node *pos, int x)
{
    node *temp=createNode(x);
    pos->next=temp;
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
    return;
}

int main()
{
    system("cls");
    int n, x; cin>>n;
    cin>>x;
    node *first = createNode(x);
    node *last = first;
    for (int i=2; i<=n; i++)
    {
        cin>>x;
        last=addNode(last, x);
    }
    
    printList(first);
    return 0;
}