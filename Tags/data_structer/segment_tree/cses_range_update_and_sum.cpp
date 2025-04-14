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

struct segment_tree_set_inc_lazy
{
    vector<ll> tree, inc, ass;
    ll n;
    segment_tree_set_inc_lazy(){}
    segment_tree_set_inc_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        inc.resize(4*n+5);
        ass.resize(4*n+5);
        build(1, 1, n);
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]=a[l];
            inc[id]=0;
            ass[id]=0;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=tree[id*2]+tree[id*2+1];
    }
    
    void increment(ll id, ll l, ll r, ll v)
    {
        inc[id]+=v;
        tree[id]+=(r-l+1)*v;
    }

    void assign(ll id, ll l, ll r, ll v)
    {
        ass[id]=v;
        tree[id]=(r-l+1)*v;
        inc[id]=0;
    }

    void pull(ll id, ll l, ll r)
    {
        ll mid=(l+r)/2;
        if (ass[id]>0)
        {
            assign(id*2, l, mid, ass[id]);
            assign(id*2+1, mid+1, r, ass[id]);
            ass[id]=0;
        }
        if (inc[id]>0)
        {
            increment(id*2, l, mid, inc[id]);
            increment(id*2+1, mid+1, r, inc[id]);
            inc[id]=0;
        }
    }

    void update_increment(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            increment(id, l, r, val);
            return;
        }
        ll mid=(l+r)/2;
        pull(id, l, r);
        update_increment(id*2, l, mid, u, v, val);
        update_increment(id*2+1, mid+1, r, u, v, val);
        tree[id]=tree[id*2]+tree[id*2+1];
    }

    void update_assign(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v)
        {
            assign(id, l, r, val);
            return;
        }
        ll mid=(l+r)/2;
        pull(id, l, r);
        update_assign(id*2, l, mid, u, v, val);
        update_assign(id*2+1, mid+1, r, u, v, val);
        tree[id]=tree[id*2]+tree[id*2+1];
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        pull(id, l, r);
        ll lsum=query(id*2, l, mid, u, v);
        ll rsum=query(id*2+1, mid+1, r, u, v);
        tree[id]=tree[id*2]+tree[id*2+1];
        return lsum+rsum;
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree_set_inc_lazy seg(n);
    while (q--)
    {
        ll t, x, y; cin>>t>>x>>y;
        if (t==1) 
        {
            ll val; cin>>val;
            seg.update_increment(1, 1, n, x, y, val);
            // for (ll i=1; i<=n; i++) cout<<seg.query(1, 1, n, i, i)<<" "; cout<<endl;
        }
        else if (t==2)
        {
            ll val; cin>>val;
            seg.update_assign(1, 1, n, x, y, val);
            // for (ll i=1; i<=n; i++) cout<<seg.query(1, 1, n, i, i)<<" "; cout<<endl;
        }
        else if (t==3)
        {
            cout<<seg.query(1, 1, n, x, y)<<endl;
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