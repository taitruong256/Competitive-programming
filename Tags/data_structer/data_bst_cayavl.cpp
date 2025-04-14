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
        node *temp=new node;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else
    {
        if (x<root->data) root->left=insertNode(root->left, x);
        else root->right=insertNode(root->right, x);
    }
}

void printTree(node *root)
{
    if (root!=NULL)
    {
        printTree(root->left);
        cout<<root->data<<" ";
        printTree(root->right);
    }
}

int treeLevel(node *root)
{
    if (root==NULL) return -1;
    return 1+max(treeLevel(root->left), treeLevel(root->right));
}

node *turnRight(node *a)
{
    node *b=a->left;
    node *d=b->right;
    b->right=a;
    a->left=d;
    return b;
}

node *turnLeft(node *a)
{
    node *b=a->right;
    node *c=b->left;
    b->left=a;
    a->right=c;
    return b;
}

node *updateTreeAvl(node *root)
{
    if (abs(treeLevel(root->left)-treeLevel(root->right))>1)
    {
        if (treeLevel(root->left)>treeLevel(root->right))//cay lech trai
        {
            node *p=root->left;
            if (treeLevel(p->left)>treeLevel(p->right)) //lech trai trai
                root=turnRight(root);
            else{         //lech trai phai
                root->left=turnLeft(root->left);
                root=turnRight(root);
            }
        }
        else  //cay lech phai
        {
            node *p=root->right;
            if (treeLevel(p->right)>treeLevel(p->left)) //cay lech phai phai
                root=turnLeft(root);
            else            //cay lech phai trai
            {
                root->right=turnRight(root->right);
                root=turnLeft(root);
            }
        }
    }
    if (root->left!=NULL) root->left=updateTreeAvl(root->left);
    if (root->right!=NULL) root->right=updateTreeAvl(root->right);
    return root;
}

bool checkAvl(node *t){
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}

int main()
{
    system("cls");
    int n; cin>>n;
    int x; cin>>x;
    node *root = new node;
    root=NULL;
    root=insertNode(root, x);
    for (int i=1; i<n; i++)
    {
        cin>>x;
        insertNode(root, x);
    }
    while (!checkAvl(root)) root=updateTreeAvl(root);
    cout<<treeLevel(root);
    return 0;
}