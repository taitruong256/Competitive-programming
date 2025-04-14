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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                                         Learn from your own mistakes
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, k, cnt, sz[100005], sz_tmp[100005]; 
vector<ll> adj[100005];

void dfs(ll u, ll p)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=p) 
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void calc(ll u, ll p, ll x)
{
    ll sum=0;
    for (auto v: adj[u]) if (v!=p)
    {
        calc(v, u, x);
        if (sz[v]>=x) 
        {
            ++cnt;
            sz[u]-=sz[v];
            sz[v]=0;
        }
        sum+=sz[v];
    }   
    sz[u]=1+sum;
}

bool check(ll x)
{
    cnt=0;
    calc(1, 0, x);
    if (sz[1]<x) --cnt;
    // for (ll i=1; i<=n; i++) cout<<sz[i]<<" "; cout<<"         "<<cnt<<endl;
    for (ll i=1; i<=n; i++) sz[i]=sz_tmp[i];
    if (cnt>=k) return true;
    return false;
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (ll i=1; i<=n; i++) sz_tmp[i]=sz[i];
    // for (ll i=1; i<=n; i++) cout<<check(i)<<endl; cout<<endl;
    ll l=1, r=n-1, ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
    for (ll i=1; i<=n; i++) adj[i].clear(), sz[i]=0;
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