#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

struct segment_tree_lazy
{
    vector<ll> tree, lazy;
    ll n;

    segment_tree_lazy(){}
    segment_tree_lazy(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    ll opt(ll x, ll y)
    {
        return max(x, y);
    }

    void down(ll id)
    {
        ll t=lazy[id];
        tree[id*2]+=t;
        lazy[id*2]+=t;
        tree[id*2+1]+=t;
        lazy[id*2+1]+=t;
        lazy[id]=0;
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        down(id);
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (l>v || r<u) return;
        if (u<=l && r<=v) 
        {
            tree[id]+=val;
            lazy[id]+=val;
            return;
        }
        ll mid=(l+r)/2;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};

segment_tree_lazy seg(200005);

void solve()
{
    ll n, r, q; cin>>n>>r>>q;
    ld p; cin>>p;
    ll ans=0;
    for (ll i=1; i<=r; i++)
    {
        ll l, r; cin>>l>>r;
        ll mx=seg.query(1, 0, 200000, l, r-1);
        if (mx<q)
        {
            ++ans;
            seg.update(1, 0, 200000, l, r-1, 1);
        }
    }
    if ((ld)(100.0-1.0*ans/r*100)<=p) cout<<ans<<"/"<<r<<": No";
    else cout<<ans<<"/"<<r<<": Yes";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // clock_t start = clock();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    solve();
    // clock_t end = clock();
    // cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}