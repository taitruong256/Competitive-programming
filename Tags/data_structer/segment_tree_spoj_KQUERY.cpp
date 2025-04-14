/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
struct query{ll l, r, k;};
const ll maxn=300005;
query q[maxn];
ll n, a[maxn], tree[4*maxn];

void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=1;
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id]=tree[id*2]+tree[id*2+1];
}

void updatetree(ll id, ll l, ll r, ll u, ll v, ll k)
{
    if (l>v || r<u) return;
    if (l==r)
    {
        tree[id]=(a[l]>k);
        return;
    }
    ll mid=(l+r)/2;
    updatetree(id*2, l, mid, u, v, k);
    updatetree(id*2+1, mid+1, r, u, v, k);
    tree[id]=tree[id*2]+tree[id*2+1];
}

ll getvalue(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return getvalue(id*2, l, mid, u, v)+getvalue(id*2+1, mid+1, r, u, v);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    buildtree(1, 1, n);
    ll qr; cin>>qr;
    while (qr--)
    {
        ll x, y, k; cin>>x>>y>>k;
        updatetree(1, 1, n, x, y, k);
        cout<<getvalue(1, 1, n, x, y)<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}