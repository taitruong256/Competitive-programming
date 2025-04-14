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
    ll value, size, priority, sum, rev;
    node *left, *right;

    node (ll _value)
    {
        value=sum=_value;
        size=1;
        priority=rand();
        rev=0;
        left=NULL;
        right=NULL;
    }
};

ll size(node *treap)
{
    if (treap==NULL) return 0;
    return treap->size;
}

ll sum(node *treap)
{
    if (treap==NULL) return 0;
    return treap->sum;
}

void down(node *&treap)
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
    down(treap);
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
    treap->sum=sum(treap->left)+sum(treap->right)+treap->value;
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
    down(left);
    down(right);
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
    treap->sum=sum(treap->left)+sum(treap->right)+treap->value;
}

void print(node *treap)
{
    if (treap==NULL) return;
    down(treap);
    print(treap->left);
    cout<<treap->value<<" ";
    print(treap->right);
}

ll getsum(node *treap, ll l, ll r, ll u, ll v)
{
    if (treap==NULL || l>r) return 0;
    if (l>v || r<u) return 0;
    down(treap);
    if (u<=l && r<=v) return treap->sum;
    ll mid=l+size(treap->left);
    ll ans=0;
    if (u<=mid && mid<=v)  ans+=treap->value;
    return ans+getsum(treap->left, l, mid-1, u, v)+getsum(treap->right, mid+1, r, u, v);
}

void solve()
{
    ll n, q; cin>>n>>q;
    node *treap=NULL;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        merge(treap, treap, new node(x));
    }
    while (q--)
    {
        ll t, x, y; cin>>t>>x>>y;
        if (t==1)
        {
            node *a, *b, *c, *d;
            split(treap, a, b, x-1);
            split(b, c, d, y-x+1);
            c->rev^=1;
            merge(treap, a, c);  
            merge(treap, treap, d);  
        }
        else 
        {
            cout<<getsum(treap, 1, size(treap), x, y)<<endl;
        }
    }
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