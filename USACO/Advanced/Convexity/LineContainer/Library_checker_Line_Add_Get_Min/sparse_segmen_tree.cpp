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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

struct sparse_segment_tree  //luu y bo nho n.logn nen de toan cuc 
{
    struct node 
    {
        ll sum, lazy;
        node *leftchild, *rightchild;
    
        node()
        {
            sum=0;
            lazy=-1;
            leftchild=rightchild=NULL;
        }
    
        ~node()
        {
            delete leftchild;
            delete rightchild;
        }
    };
    ll maxn;
    node *root=new node();
 
    sparse_segment_tree(){}
    sparse_segment_tree(ll _maxn)
    {
        maxn=_maxn;
    }
    
    void extend(node *root, ll l, ll r)
    {
        if (l!=r)
        {
            if (root->leftchild==NULL) root->leftchild=new node();
            if (root->rightchild==NULL) root->rightchild=new node();
        }
    }
    
    void down(node *root, ll l, ll r)
    {
        if (root->lazy!=-1)
        {
            if (l!=r)
            {
                ll mid=(l+r)/2;
                extend(root, l, r);
                root->leftchild->lazy=root->lazy;
                root->rightchild->lazy=root->lazy;
                root->leftchild->sum=(mid-l+1)*root->lazy;
                root->rightchild->sum=(r-mid)*root->lazy;
            }   
            root->lazy=-1;
        }
    }
    
    void update(node *root, ll l, ll r, ll u, ll v, ll val)
    {
        down(root, l, r);
        if (l>v || r<u || u>v) return;   
        if (u<=l && r<=v) 
        {
            root->lazy=val;
            root->sum=(r-l+1)*val;
            return;
        }
        extend(root, l, r);
        ll mid=(l+r)/2;
        update(root->leftchild, l, mid, u, v, val);
        update(root->rightchild, mid+1, r, u, v, val);
        root->sum = root->leftchild->sum + root->rightchild->sum;  
    }
    
    ll query(node *root, ll l, ll r, ll u, ll v)
    {
        down(root, l, r);
        if (l>v || r<u || u>v) return 0;
        if (u<=l && r<=v) return root->sum;
        extend(root, l, r);
        ll mid=(l+r)/2;
        return query(root->leftchild, l, mid, u, v) + query(root->rightchild, mid+1, r, u, v);
    }
};
sparse_segment_tree seg(1e18);
ll n, m, a[100005];

void solve()
{
    seg.update(seg.root, 1, 1e18, 1, 1e18, 0);
    ll n; cin>>n;
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        ans+=seg.query(seg.root, 1, 1e18, x+1, 1e18);
        seg.update(seg.root, 1, 1e18, x, x, 1);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}