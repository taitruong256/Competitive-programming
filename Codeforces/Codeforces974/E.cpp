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
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, m, h, a[200005], d1[200005], d2[200005];
vector<pair<ll, ll>> adj[200005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
 
void dijktra1(ll s)
{
    for (ll i=1; i<=n; i++) d1[i]=1e18;
    pq.push({0, s});
    d1[s]=0;
 
    while (!pq.empty())
    {
        auto [wu, u]=pq.top();
        pq.pop();
        if (wu>d1[u]) continue;
        for (auto [v, w]: adj[u]) 
        {
            if (d1[u]+w<d1[v])
            {
                d1[v]=d1[u]+w;
                pq.push({d1[v], v});
            }
        }
    }
}

void dijktra2(ll s)
{
    for (ll i=1; i<=n; i++) d2[i]=1e18;
    pq.push({0, s});
    d2[s]=0;
 
    while (!pq.empty())
    {
        auto [wu, u]=pq.top();
        pq.pop();
        if (wu>d2[u]) continue;
        for (auto [v, w]: adj[u]) 
        {
            if (d2[u]+w<d2[v])
            {
                d2[v]=d2[u]+w;
                pq.push({d2[v], v});
            }
        }
    }
}
 
void solve()
{
    cin>>n>>m>>h;    
    for (ll i=1; i<=h; i++)
    {
        ll x; cin>>x;
        a[x]=1;
    }
    for (ll i=1; i<=m; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijktra1(1);
    while (!pq.empty()) pq.pop();

    dijktra2(n);
    while (!pq.empty()) pq.pop();

    for (ll i=1; i<=n; i++) cout<<d1[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<d2[i]<<" "; cout<<endl;

    ll ans=1e18;
    for (ll i=1; i<=n; i++) if (a[i]==1) 
        ans=min(ans, min(d1[i]+d2[i]/2, d1[i]/2+d2[i]));
    if (ans>=1e17) ans=-1;
    cout<<ans<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear(), a[i]=0;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}