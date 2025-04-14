/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort  */
/*       __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll a[200005], tree[800005];
ll n, q;

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
    tree[id]=min(tree[id*2], tree[id*2+1])
}

ll get_value(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 2*inf;
    if (u<=l && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return min(get_value(id*2, l, mid, u, v), get_value(id*2+1, mid+1, r, u, v));
}

void update(ll id, ll l, ll r, ll u, ll val)
{
    if (l>u || r<u) return;
    if (u==l && u==r) 
    {
        tree[id]=val;
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, u, val);
    update(id*2+1, mid+1, r, u, val);
    tree[id]=min(tree[id*2], tree[id*2+1]);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll t; cin>>t;
        if (t==1) 
        {
            ll id, val; cin>>id>>val;
            update(1, 1, n, id, val);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<get_value(1, 1, n, l, r)<<endl;
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
