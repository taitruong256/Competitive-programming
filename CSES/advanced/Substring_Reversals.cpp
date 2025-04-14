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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

struct node 
{
    ll size, priority, rev;
    char key;
    node *left, *right;

    node(ll _key)
    {
        key=_key;
        size=1;
        rev=0;
        priority=rand();
        left=NULL;
        right=NULL;
    }
};

ll size(node *treap)
{
    if (treap==NULL) return 0;
    return treap->size;
}

void update(node *&treap)
{
    if (treap==NULL) return;
    if (treap->rev==1)
    {
        treap->rev=0;
        swap(treap->left, treap->right);
        if (treap->left!=NULL) treap->left->rev^=1;
        if (treap->right!=NULL) treap->right->rev^=1;
    }
}

void split(node *treap, node *&left, node *&right, ll pos)
{
    if (treap==NULL)
    {
        left=right=NULL;
        return;
    }
    update(treap);
    if (size(treap->left)<pos)
    {
        split(treap->right, treap->right, right, pos-size(treap->left)-1);
        left=treap;
    } 
    else 
    {
        split(treap->left, left, treap->left, pos);
        right=treap;
    }
    treap->size=size(treap->left)+size(treap->right)+1;
}

void merge(node *&treap, node *left, node *right)
{
    if (left==NULL)
    {
        treap=right;
        return;
    }
    if (right==NULL)
    {
        treap=left;
        return;
    }
    update(left);
    update(right);
    if (left->priority<=right->priority)
    {
        merge(right->left, left, right->left);
        treap=right;
    }
    else 
    {
        merge(left->right, left->right, right);
        treap=left;
    }
    treap->size=size(treap->left)+size(treap->right)+1;
}

void print(node *treap)
{
    if (treap==NULL) return;
    update(treap);
    print(treap->left);
    cout<<treap->key;
    print(treap->right);
}

void solve()
{
    ll n, q; cin>>n>>q;
    string s; cin>>s;
    s=" "+s;
    node *treap=NULL;
    for (ll i=1; i<=n; i++) merge(treap, treap, new node(s[i]));
    while (q--)
    {
        ll x, y; cin>>x>>y;
        node *a, *b, *c, *d;  
        split(treap, a, b, x-1);
        split(b, c, d, y-x+1);
        c->rev^=1;
        merge(treap, a, c);
        merge(treap, treap, d);
    }
    print(treap);
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