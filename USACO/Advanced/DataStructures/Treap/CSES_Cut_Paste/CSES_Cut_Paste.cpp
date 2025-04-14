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
        ll prior, sz; 
        node *l, *r;
        node () {l=NULL; r=NULL;}
        node (ll _key)
        {
            key=_key;
            prior=rand();
            sz=1;
            l=NULL;
            r=NULL;
        }
    };

    node *root=NULL;

    inline ll size(node *root)
    {
        if (root==NULL) return 0;
        return root->sz;
    }

    void split(node *root, node *&left, node *&right, ll k)
    {
        if (root==NULL) 
        {
            left=right=NULL;
            return;
        }
        if (size(root->l)<k)   //sua lai root.key<=k tuy de bai
        {
            split(root->r, root->r, right, k-size(root->l)-1);
            left=root;
        }
        else 
        {
            split(root->l, left, root->l, k);
            right=root;
        }
        root->sz=size(root->l)+size(root->r)+1;
    }

    void merge(node *&root, node *left, node *right)
    {
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
            merge(left->r, left->r, right);
            root=left;
        }
        else 
        {
            merge(right->l, left, right->l);
            root=right;
        }
        root->sz=size(root->l)+size(root->r)+1;
    }

    void insert(char c)
    {
        node *new_node=new node(c);
        merge(root, root, new_node);
    }

    void cut_paste(ll l, ll r)
    {
        node *a, *b, *c, *d; 
        split(root, a, b, r);
        split(a, c, d, l-1);
        merge(root, c, b);
        merge(root, root, d);
    }

    void print(node *treap)
    {
        if (treap!=NULL) 
        {
            print(treap->l);
            cout<<treap->key;
            print(treap->r);
        }
    }
};

void solve()
{
    ll n, q; cin>>n>>q;
    string s; cin>>s; 
    Treap treap;
    for (auto c: s) treap.insert(c);
    while (q--)
    {
        ll l, r; cin>>l>>r;
        treap.cut_paste(l, r);
    }
    treap.print(treap.root);
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