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
    ll value, maxval, size, priority;
    node *left, *right;

    node (ll _val)
    {
        value=maxval=_val;
        size=1;
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
    treap->size=size(treap->left)+size(treap->right)+1;
    treap->maxval=treap->value;
    if (treap->left!=NULL) treap->maxval=max(treap->maxval, treap->left->maxval);
    if (treap->right!=NULL) treap->maxval=max(treap->maxval, treap->right->maxval);
}

void split(node *treap, node *&left, node *&right, ll value)
{
    if (treap==NULL)
    {
        left=right=NULL;
        return;
    }
    if (size(treap->left)<value) 
    {
        split(treap->right, treap->right, right, value-size(treap->left)-1);
        left=treap;
    }
    else 
    {
        split(treap->left, left, treap->left, value);
        right=treap;
    }
    update(treap);
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
    if (left->priority <= right->priority)
    {
        merge(right->left, left, right->left);
        treap=right;
    }
    else 
    {
        merge(left->right, left->right, right);
        treap=left;
    }
    update(treap);
}

void print(node *treap)
{
    if (treap==NULL) return;
    print(treap->left);
    cout<<treap->value<<" ";
    print(treap->right);
}

ll getmax(node *treap, ll l, ll r, ll u, ll v)
{
    if (treap==NULL || l>r) return -1e18;
    if (l>v || r<u) return -1e18;
    if (u<=l && r<=v) return treap->maxval;
    ll mid=l+size(treap->left);
    ll res=-1e18;
    if (u<=mid && mid<=v) res=max(res, treap->value);
    return max({res, getmax(treap->left, l, mid-1, u, v), getmax(treap->right, mid+1, r, u, v)});
}

void solve()
{
    node *treap=NULL;
    ll q; cin>>q;
    while (q--)
    {
        char c; cin>>c;
        ll x, y; cin>>x>>y;
        if (c=='A')
        {
            node *a, *b;
            split(treap, a, b, y-1);
            merge(treap, a, new node(x));
            merge(treap, treap, b);
        }
        else 
        {
            cout<<getmax(treap, 1, size(treap), x, y)<<endl;
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