#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << (#x) << " is " << (x) << endl
#define For(i,a,b) for(ll i=a; i<b;i++)

struct node
{
    int data;
    node *next;
};

node *createNode(int x)
{
    node *temp = new node;
    temp->data=x;
    temp->next=NULL;
    return temp;
}

node *addNode(node *last, int x)
{
    node *temp=createNode(x);
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
}

node *deleteNode(node *first, int k)
{
    if (k==0)
    {
        node *temp=first;
        first=first->next;
        delete(temp);
        return first;
    }
    else 
    {
        node *pos=first;
        for (int i=0; i<k-1; i++) pos=pos->next;
        node *temp=pos->next;
        pos->next=pos->next->next;
        delete(temp);
        return first;
    }
}

int main()
{   
    //system("cls");
    int n, x; cin>>n;
    cin>>x;
    node *first = createNode(x);
    node *last = first;
    for (int i=1; i<n; i++)
    {
        cin>>x;
        last=addNode(last, x);
    }
    int k; cin>>k;
    first=deleteNode(first, k);
    printList(first);
    return 0;
}