#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
struct DSU
{
    ll n, tplt, mx;
    vector<ll> par, sz;
    DSU();
    DSU(ll _n)
    {
        n=_n;
        tplt=n;
        mx=1;
        par.resize(n+5);
        sz.resize(n+5);
        for (ll i=1; i<=n; i++) par[i]=i;
        for (ll i=1; i<=n; i++) sz[i]=1;
    }

    ll get(ll u)
    {
        if (u==par[u]) return u;
        return par[u]=get(par[u]);
    }

    void merge(ll u, ll v)
    {
        u=get(u);
        v=get(v);
        if (u==v) return;
        if (sz[u]<sz[v]) swap(u, v);
        par[v]=u;
        sz[u]+=sz[v];
        --tplt;
        mx=max(mx, sz[u]);
    }
};


void solve()
{
    ll n, m; cin>>n>>m;
    DSU d(n);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        d.merge(u, v);
        cout<<d.tplt<<" "<<d.mx<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
