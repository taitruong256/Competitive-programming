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
ll n, q, a[200005];
 
struct segment_tree_lazy
{
    vector<ll> tree, lazy1, lazy2;
    ll n;
    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy1.resize(4*n+5);
        lazy2.resize(4*n+5);
        build(1, 1, n);
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=a[l];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
    void down(ll id, ll l, ll r)
    {
        ll mid=(l+r)/2;
        if (lazy1[id]!=0)
        {
            lazy1[id*2  ]+=lazy1[id];
            tree [id*2  ]+=lazy1[id]*(mid-l+1);
            lazy1[id*2+1]+=lazy1[id];
            tree [id*2+1]+=lazy1[id]*(r-mid);
            lazy1[id]=0;
        }
        if (lazy2[id]!=0)
        {
            lazy2[id*2  ]+=lazy2[id];
            tree [id*2  ]+=lazy2[id]*(mid*(mid+1)/2-l*(l-1)/2);
            lazy2[id*2+1]+=lazy2[id];
            tree [id*2+1]+=lazy2[id]*(r*(r+1)/2-mid*(mid+1)/2);
            lazy2[id]=0;
        }
    }
    ll getvalue(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id, l, r);
        ll sum_left=getvalue(id*2, l, mid, u, v);
        ll sum_right=getvalue(id*2+1, mid+1, r, u, v);
        return sum_left+sum_right;
    }
    void update(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=(r-u+1)*(r-u+1+1)/2-(l-u+1)*(l-u+1-1)/2;
            lazy1[id]+=-u+1;
            lazy2[id]+=1;
            return;
        }
        ll mid=(l+r)/2;
        down(id, l, r);
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
};
 
void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree_lazy st(n);
    while (q--)
    {
        ll type, u, v; cin>>type>>u>>v;
        if (type==1) st.update(1, 1, n, u, v);
        else cout<<st.getvalue(1, 1, n, u, v)<<endl;
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