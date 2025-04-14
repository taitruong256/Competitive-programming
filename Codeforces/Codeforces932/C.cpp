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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;
ll n, lim, dp[2005][2005];
pair<ll, ll> a[2005];

struct segment_tree
{
    vector<ll> tree;
    ll n;

    void init(ll _n)
    {
        n=_n;
        tree.resize(4*n+5, 1e18);
    }

    ll opt(ll x, ll y)
    {
        return min(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 1e18;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l==r) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        if (pos<=mid) update(id*2, l, mid, pos, v);
        else update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
} seg[2005];

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

void solve()
{
    cin>>n>>lim;
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    sort(a+1, a+n+1, comp);

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            dp[i][j]=1e18;

    for (ll i=1; i<=n; i++) seg[i].init(n);

    for (ll j=1; j<=n; j++) 
    {
        dp[1][j]=a[j].first;
        seg[1].update(1, 1, n, j, dp[1][j]-a[j].second);
    }

    for (ll i=2; i<=n; i++)
    {
        for (ll j=i; j<=n; j++)
        {
            dp[i][j]=a[j].first+a[j].second+seg[i-1].query(1, 1, n, i-1, j-1);
            seg[i].update(1, 1, n, j, dp[i][j]-a[j].second);
        }
    }

    ll ans=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            if (dp[i][j]<=lim)
                ans=i;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}