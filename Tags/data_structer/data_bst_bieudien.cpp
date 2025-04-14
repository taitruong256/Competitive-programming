#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insertNode(node *root, int x)
{  
    if (root==NULL)
    {
        node *temp = new node;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else 
    {
        if (x<root->data)
          {  root->left=insertNode(root->left, x);}
        else
          {  root->right=insertNode(root->right, x);}
    }
}

void prinfTree(node *root)
{  
    if (root!=NULL)
    {
        prinfTree(root->left);
        cout<<root->data<<" ";
        prinfTree(root->right);
    }
}

int main()
{
    system("cls");
    int n; cin>>n;
    node *root = NULL;

    for (int i=0; i<n; i++)
    {
        int x; cin>>x;
        root=insertNode(root, x);
    }
    prinfTree(root); 
    return 0;
}