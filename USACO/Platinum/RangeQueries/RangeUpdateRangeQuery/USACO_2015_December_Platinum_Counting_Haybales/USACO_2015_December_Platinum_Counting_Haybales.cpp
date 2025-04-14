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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

ll n, m, a[200005];

struct segment_tree_lazy
{
    vector<ll> sum, mn, lazy;
    ll n;
    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        sum.resize(4*n+5, 0);
        mn.resize(4*n+5, 1e18);
        lazy.resize(4*n+5, 0);
        build(1, 1, n);
    }
    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            sum[id]=a[l];
            mn[id]=a[l];
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        sum[id]=sum[id*2]+sum[id*2+1];
        mn[id]=min(mn[id*2], mn[id*2+1]);
    }
    void down(ll id, ll l, ll r)
    {
        if (lazy[id]!=0)
        {
            sum[id]+=(r-l+1)*lazy[id];
            mn[id]+=lazy[id];
            if (l!=r)
            {
                lazy[id*2]+=lazy[id];
                lazy[id*2+1]+=lazy[id];
            }
            lazy[id]=0;
        }
    }
    ll query_sum(ll id, ll l, ll r, ll u, ll v)
    {
        down(id, l, r);
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return sum[id];
        ll mid=(l+r)/2;
        return query_sum(id*2, l, mid, u, v)+query_sum(id*2+1, mid+1, r, u, v);
    }
    ll query_min(ll id, ll l, ll r, ll u, ll v)
    {
        down(id, l, r);
        if (l>v || r<u) return 1e18;
        if (u<=l && r<=v) return mn[id];
        ll mid=(l+r)/2;
        return min(query_min(id*2, l, mid, u, v), query_min(id*2+1, mid+1, r, u, v));
    }
    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        down(id, l, r);
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            lazy[id]+=val;
            down(id, l, r);
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        sum[id]=sum[id*2]+sum[id*2+1];
        mn[id]=min(mn[id*2], mn[id*2+1]);
    }
};

void solve()
{
    setIO("haybales");
    cin>>n>>m; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree_lazy seg(n);
    while (m--)
    {
        char c; cin>>c; 
        if (c=='M')
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query_min(1, 1, n, l, r)<<endl;
        }
        else if (c=='S')
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query_sum(1, 1, n, l, r)<<endl;
        }
        else 
        {
            ll l, r, c; cin>>l>>r>>c;
            seg.update(1, 1, n, l, r, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}