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
struct node{ll val, lazy;};
node tree[4*maxn];
ll n, q;
void buildtree(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id].val=tree[id].lazy=0;
        return;
    }
    ll mid=(l+r)/2;
    buildtree(id*2, l, mid);
    buildtree(id*2+1, mid+1, r);
    tree[id].val=max(tree[id*2].val, tree[id*2+1].val);
}

void down(ll id)
{
    ll t=tree[id].lazy;
    tree[id*2].val+=t;
    tree[id*2].lazy+=t;
    tree[id*2+1].val+=t;
    tree[id*2+1].lazy+=t;
    tree[id].lazy=0;
}

void updatetree(ll id, ll l, ll r, ll u, ll v, ll k)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        tree[id].val+=k;
        tree[id].lazy+=k;
        return;
    }
    ll mid=(l+r)/2;
    down(id);
    updatetree(id*2, l, mid, u, v, k);
    updatetree(id*2+1, mid+1, r, u, v, k);
    tree[id].val=max(tree[id*2].val, tree[id*2+1].val);
}

ll getvalue(ll id, ll l, ll r, ll u, ll v)
{
    if (r<u || l>v) return -1e9;
    if (l>=u && r<=v) return tree[id].val;
    ll mid=(l+r)/2;
    down(id);
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