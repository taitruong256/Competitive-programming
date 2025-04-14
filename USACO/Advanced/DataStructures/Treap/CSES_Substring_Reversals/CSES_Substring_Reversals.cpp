/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct Treap
{
    struct node 
    { 
        char key;
        ll prior, size, rev; 
        node *left, *right;

        node () 
        {
            left=NULL;
            right=NULL;
        }
        node (char _key)
        {
            key=_key;
            prior=rand();
            size=1;
            rev=0;
            left=NULL;
            right=NULL;
        }
    };

    node *Root=NULL;

    inline ll getsz(node *root)
    {
        if (root==NULL) return 0;
        return root->size;
    }

    void push_down(node *&root)
    {
        if (root==NULL) return;
        if (root->rev==1)
        {
            root->rev=0;
            swap(root->left, root->right);
            if (root->left!=NULL) root->left->rev^=1;
            if (root->right!=NULL) root->right->rev^=1;
        }
    }

    void split(node *root, node *&left, node *&right, ll k)
    {
        push_down(root);
        if (root==NULL)
        {
            left=right=NULL;
            return;
        }
        if (getsz(root->left)<k)
        {
            split(root->right, root->right, right, k-getsz(root->left)-1);
            left=root;
        }
        else 
        {
            split(root->left, left, root->left, k);
            right=root;
        }
        root->size=getsz(root->left)+getsz(root->right)+1;
    }

    void merge(node *&root, node *left, node *right)
    {
        push_down(left);
        push_down(right);
        if (left==NULL)
        {
            root=right;
            return;
        }
        if (right==NULL)
        {
            root=left;
            return;
        }
        if (left->prior>right->prior)
        {
            merge(left->right, left->right, right);
            root=left;
        }
        else 
        {
            merge(right->left, left, right->left);
            root=right;
        }
        root->size=getsz(root->left)+getsz(root->right)+1;
    }

    void insert(char c)
    {
        node *new_node=new node(c);
        merge(Root, Root, new_node);
    }

    void update(ll l, ll r)
    {
        node *a, *b, *c, *d;
        split(Root, a, b, r);
        split(a, c, d, l-1);
        d->rev^=1;
        merge(Root, c, d);
        merge(Root, Root, b);
    }

    void print(node *root)
    {
        push_down(root);
        if (root==NULL) return;
        print(root->left);
        cout<<root->key;
        print(root->right);
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    string s; cin>>s;
    Treap treap;
    for (char c: s) treap.insert(c);
    while (q--)
    {
        ll l, r; cin>>l>>r;
        treap.update(l, r);
    }
    treap.print(treap.Root);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}