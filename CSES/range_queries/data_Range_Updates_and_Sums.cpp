/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __ __   ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, q;
ll a[200005], sum[800005], addval[800005], setval[800005];

void pull(ll id)
{
    sum[id]=sum[id*2]+sum[id*2+1];
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        sum[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    pull(id);   
}

void increment(ll id, ll l, ll r, ll val)
{
    addval[id]+=val;
    sum[id]+=(r-l+1)*val;
}

void assign(ll id, ll l, ll r, ll val)
{
    setval[id]=val;
    addval[id]=0;
    sum[id]=(r-l+1)*val;
}

void push(ll id, ll l, ll r)
{
    if (setval[id])
    {
        assign(id*2, l, r, setval[id]);
        assign(id*2+1, l, r, setval[id]);
        setval[id]=0;
    }
    if (addval[id])
    {
        increment(id*2, l, r, addval[id]);
        increment(id*2+1, l, r, addval[id]);
        addval[id]=0;
    }
}

void update_increase(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        increment(id, l, r, val);
        return;
    }
    push(id, l, r);
    ll mid=(l+r)/2;
    update_increase(id*2, l, mid, u, v, val);
    update_increase(id*2+1, mid+1, r, u, v, val);
    pull(id);
}

void update_assign(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        assign(id, l, r, val);
        return;
    }
    push(id, l, r);
    ll mid=(l+r)/2;
    update_assign(id*2, l, mid, u, v, val);
    update_assign(id*2+1, mid+1, r, u, v, val);
    pull(id);
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return sum[id];
    push(id, l, r);
    ll mid=(l+r)/2;
    ll left=query(id*2, l, mid, u, v);
    ll right=query(id*2+1, mid+1, r, u, v);
    pull(id);
    return left+right;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    memset(sum, 0, sizeof(sum));
    memset(addval, 0, sizeof(addval));
    memset(setval, 0, sizeof(setval));
    build(1, 1, n);
    while (q--)
    {
        ll t, a, b; cin>>t>>a>>b;
        if (t==1)
        {
            ll x; cin>>x;
            update_increase(1, 1, n, a, b, x);
        }
        else if (t==2)
        {
            ll x; cin>>x;
            update_assign(1, 1, n, a, b, x);
        }
        else cout<<query(1, 1, n, a, b)<<endl;
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