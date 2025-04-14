#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, q, h[100005], w[100005];

struct fenwick_2D
{
    ll n, m;
    vector<vector<ll>> bit;
    fenwick_2D () {}
    fenwick_2D (ll _n, ll _m) 
    {
        n=_n;
        m=_m;
        bit.resize(n+5, vector<ll> (m+5));
    }
    void update(ll x, ll y, ll val)
    {
        for (ll i=x; i<=n; i+=-i&i)
            for (ll j=y; j<=m; j+=-j&j) bit[i][j]+=val;
    }
    ll query(ll x, ll y)
    {
        ll sum=0;
        for (ll i=x; i>0; i-=-i&i)
            for (ll j=y; j>0; j-=-j&j) sum+=bit[i][j];
        return sum;
    }
    ll query_range(ll x1, ll y1, ll x2, ll y2)
    {
        return query(x2, y2)-query(x1-1, y2)-query(x2, y1-1)+query(x1-1, y1-1);
    }
};
 
fenwick_2D ft = fenwick_2D(1030, 1030);
 
void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>h[i]>>w[i];
    for (ll i=1; i<=n; i++) ft.update(h[i], w[i], h[i]*w[i]);
    while(q--)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<<ft.query_range(x1+1, y1+1, x2-1, y2-1)<<endl;
    }
    for (ll i=1; i<=n; i++) ft.update(h[i], w[i], -h[i]*w[i]);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}
