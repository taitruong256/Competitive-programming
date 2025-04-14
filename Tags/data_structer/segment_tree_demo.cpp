/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=500005;
ll a[4*maxn], tree[4*maxn];
ll n, q;
void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=0;
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id]=max(tree[id*2], tree[id*2+1]);
}

void updatetree(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (r<u || l>v) return;
    if (l==r)
    {
        tree[id]+=val;
        return;
    }
    ll mid=(l+r)/2;
    updatetree(id*2, l, mid, u, v, val);
    updatetree(id*2+1, mid+1, r, u, v, val);
    tree[id]=max(tree[id*2], tree[id*2+1]);
}

ll getvalue(ll id, ll l, ll r, ll u, ll v)
{
    if (r<u || l>v) return -1e18;
    if (l>=u && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return max(getvalue(id*2, l, mid, u, v), getvalue(id*2+1, mid+1, r, u, v));
}

void solve()
{
    cin>>n>>q;
    buildtree(1, 1, n);
    for (ll i=0; i<q; i++) 
    {
        ll t, x, y, v;
        cin>>t;
        if (t==0)
        {
            cin>>x>>y>>v;
            updatetree(1, 1, n, x, y, v);
        }
        else 
        {
            cin>>x>>y;
            cout<<getvalue(1, 1, n, x, y)<<endl;
        }
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