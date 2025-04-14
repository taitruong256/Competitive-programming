#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
#define endl '\n'
#define orderset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
ll n, q, a[30005], ans[200005],  cnt[1000005], pre[1000005];
vector<pair<ll, ll>> query[30005];

struct fenwick
{
    ll n;
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll s=0;
        for (ll i=idx; i>0; i-=-i&i) s+=bit[i];
        return s;
    }
};

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        query[r].push_back({l, i});
    }

    fenwick ft(n);
    for (ll r=1; r<=n; r++)
    {
        if (pre[a[r]]) ft.update(pre[a[r]], -1);
        pre[a[r]]=r;
        ft.update(r, 1);
        ll sr=ft.query(r);
        for (auto [l, idx]: query[r]) ans[idx]=sr-ft.query(l-1);
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
