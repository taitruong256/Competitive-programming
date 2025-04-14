/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, q, b, tree[400005], lazy[400005];

void build(ll id, ll l, ll r)
{                
    if (l==r)
    {
        tree[id]=b;
        lazy[id]=0;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=tree[id*2]+tree[id*2+1];
}

void pull(ll id, ll l, ll r)
{
    ll t=lazy[id];
    if (t>0)
    {
        ll mid=(l+r)/2;
        lazy[id*2]=t;
        tree[id*2]=(mid-l+1)*t;
        lazy[id*2+1]=t;
        tree[id*2+1]=(r-mid)*t;
        lazy[id]=0;
    }
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        tree[id]=(r-l+1)*val;
        lazy[id]=val;
        return;
    }
    ll mid=(l+r)/2;
    pull(id, l, r);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    tree[id]=tree[id*2]+tree[id*2+1];
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return tree[id];
    ll mid=(l+r)/2;
    pull(id, l, r);
    ll suml=query(id*2, l, mid, u, v);
    ll sumr=query(id*2+1, mid+1, r, u, v);
    tree[id]=tree[id*2]+tree[id*2+1];
    return suml+sumr;
}

void solve()
{
    cin>>n>>q>>b;
    build(1, 1, n);
    while (q--)
    {
        ll type, x, y; cin>>type>>x>>y;
        if (type==1)
        {
            ll val; cin>>val;
            update(1, 1, n, x, y, val);
            // for (ll i=1; i<=n; i++) cout<<query(1, 1, n, i, i)<<" "; cout<<endl;
        }
        else 
        {
            cout<<query(1, 1, n, x, y)<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}