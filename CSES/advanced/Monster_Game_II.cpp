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

struct Line
{
    ll a, b;

    ll get(ll x)
    {
        return a*x+b;
    }
};

ll n, x, s[200005], f[200005], low[4000005], high[4000005];
Line seg[4000005];

void build(ll id, ll l, ll r)
{
    low[id]=l; high[id]=r;
    seg[id]={0LL, (ll)(1e19)};
    if (l==r) return;
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}

void update(ll id, Line L)
{
    ll l=low[id], r=high[id];
    if (l==r)
    {
        if (L.get(l)<seg[id].get(l)) seg[id]=L;
        return;
    }
    ll mid=(l+r)/2;
    if (seg[id].a<L.a) swap(seg[id], L);
    if (seg[id].get(mid)>L.get(mid))
    {
        swap(seg[id], L);
        update(id*2, L);
    }
    else update(id*2+1, L);
}

ll query(ll id, ll pos)
{
    ll l=low[id], r=high[id];
    if (l==r) return seg[id].get(pos);
    ll mid=(l+r)/2;
    if (pos<=mid) return min(seg[id].get(pos), query(id*2, pos));
    else return min(seg[id].get(pos), query(id*2+1, pos));
}

void solve()
{
    cin>>n>>x;
    for (ll i=1; i<=n; i++) cin>>s[i];
    for (ll i=1; i<=n; i++) cin>>f[i];
    build(1, 1, 1e6);
    update(1, {x, 0LL});
    for (ll i=1; i<=n; i++)
    {
        ll best=query(1LL, s[i]);
        update(1LL, {f[i], best});
    }
    cout<<query(1LL, s[n]);
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