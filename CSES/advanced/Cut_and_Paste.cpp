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
    char data;
    ll size, weight;
    node *left, *right;

    node (char c)
    {
        data=c;
        size=1;
        weight=rand();
        left=NULL;
        right=NULL;
    }
};

ll size(node *treap)
{
    if (treap==NULL) return 0;
    return treap->size;
}

void split(node *treap, node *&left, node *&right, ll k)
{
    if (treap==NULL)
    {
        left=right=NULL;
        return;
    }
    if (size(treap->left)<k)
    {
        split(treap->right, treap->right, right, k-size(treap->left)-1);
        left=treap;
    }
    else 
    {
        split(treap->left, left, treap->left, k);
        right=treap;
    }
    treap->size=size(treap->left)+size(treap->right)+1;
}

void merge(node*&treap, node *left, node *right)
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
    if (left->weight < right->weight)
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
    print(treap->left);
    cout<<treap->data;
    print(treap->right);
}



void solve()
{
    ll n, q; cin>>n>>q;
    string s; cin>>s; 
    s=" "+s;
    node *treap=NULL;
    for (ll i=1; i<=n; i++) merge(treap, treap, new node (s[i]));
    while (q--)
    {
        ll x, y; cin>>x>>y;  
        node *a, *b, *c, *d;
        split(treap, a, b, x-1);        
        split(b, c, d, y-x+1);          
        merge(treap, a, d);
        merge(treap, treap, c);
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