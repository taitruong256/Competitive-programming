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
        ll key, prior, size, mx;
        node *left, *right;
        node () 
        {
            left=NULL;
            right=NULL;
        }
        node (ll _key)
        {
            key=_key;
            prior=rand();
            size=1;
            mx=_key;
            left=NULL;
            right=NULL;
        }
    };
    node *Root=NULL;
 
    inline ll getsize(node *root)
    {
        if (root==NULL) return 0;
        return root->size;
    }
 
    inline ll getmax(node *root)
    {
        if (root==NULL) return 0;
        return root->mx;
    }

    inline ll getkey(node *root)
    {
        if (root==NULL) return 0;
        return root->key;
    }
 
    void push_up(node *&root)
    {
        root->size=getsize(root->left)+getsize(root->right)+1;
        root->mx=max({getmax(root->left), getmax(root->right), root->key});
    }
 
    void split(node *root, node *&left, node *&right, ll pos)
    {
        if (root==NULL)
        {
            left=right=NULL;
            return;
        }
        if (getsize(root->left)<pos)
        {
            split(root->right, root->right, right, pos-getsize(root->left)-1);
            left=root;
        }
        else 
        {
            split(root->left, left, root->left, pos);
            right=root;
        }
        push_up(root);
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
            merge(left->right, left->right, right);
            root=left;
        }
        else 
        {
            merge(right->left, left, right->left);
            root=right;
        }
        push_up(root);
    }
 
    void insert(ll key)
    {
        node *new_node=new node(key);
        merge(Root, Root, new_node);
    }
 
    ll query(node *root, ll l, ll r, ll u, ll v)
    {
        if (l>r || root==NULL) return 0;
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return root->mx;
        ll mid=l+getsize(root->left), ans=0;
        if (u<=mid && mid<=v) ans=max(ans, root->key);
        return max({ans, query(root->left, l, mid-1, u, v), query(root->right, mid+1, r, u, v)});
    }

    ll query_pos(node *root, ll l, ll r, ll val)
    {
        if (l==r) return l;
        ll mid=l+getsize(root->left);
        if (getmax(root->left)>=val) return query_pos(root->left, l, mid-1, val);
        if (getkey(root)>=val) return mid;
        return query_pos(root->right, mid+1, r, val);
    }

    void cut(ll l, ll r)
    {
        node *a, *b, *c, *d; 
        split(Root, a, b, r);
        split(a, c, d, l-1);
        merge(Root, c, b);
    }
 
    void print(node *root)
    {
        if (root==NULL) return;
        print(root->left);
        cout<<root->key<<" ";
        print(root->right);
    }
};
ll n, k, a[100005];
 
void solve()
{
    cin>>n>>k;
    Treap treap;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        treap.insert(a[i]);
    }
    vector<ll> ans;
    for (ll i=1; i<=n; i++) 
    {
        ll m=treap.getsize(treap.Root);
        ll val=treap.query(treap.Root, 1, m, 1, min(1+k, m));
        ll pos=treap.query_pos(treap.Root, 1, m, val);  
        ans.push_back(val);
        treap.cut(pos, pos);
        k-=pos-1;
    }
    for (auto i: ans) cout<<i<<" ";
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