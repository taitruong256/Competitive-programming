/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
         __                    __
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
const ll maxn = 200005;
ll a[maxn], tree[4*maxn], idx[maxn];
ll n, q;
 
void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=a[l];
        idx[l]=id;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=max(tree[id*2], tree[id*2+1]);
}
 
ll find(ll id, ll l, ll r, ll val)
{
    if (l==r) return l;
    ll mid=(l+r)/2;
    if (tree[id*2]>=val) return find(id*2, l, mid, val);
    else return find(id*2+1, mid+1, r, val);
}
 
void update(ll pos, ll val)
{
    a[pos]-=val;
    ll id=idx[pos]; 
    tree[id]=a[pos];
    id/=2;
    while (id>0)
    {
        tree[id]=max(tree[id*2], tree[id*2+1]);
        id/=2;
    }
}
 
void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while (q--)
    {
        ll x; cin>>x;
        if (x>tree[1])
        {
            cout<<0<<" ";
            continue;
        }
        ll ans=find(1, 1, n, x);
        cout<<ans<<" ";
        update(ans, x);
        // for (ll i=1; i<=4*n; i++) cout<<tree[i]<<" "; cout<<endl;
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