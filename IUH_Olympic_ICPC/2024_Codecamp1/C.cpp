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

ll n, m, q, s, d[100005], ans=1e18;
vector<tuple<ll, ll, ll>> adj[100005];
vector<pair<ll, ll>> queries[100005];
ll par[100005][20], mx[100005][20];
ll timein[100005], timeout[100005], timedfs=0;
ll sub[100005], dp[100005], distances[100005], dx[100005];
string res[100005];

bool check(ll mid, ll u)
{
    ll ans=0;
    for (ll i=18; i>=0; i--) if (mid&(1LL<<i)) 
    {
        ans=max(ans, mx[u][i]);
        u=par[u][i];
    }
    if (ans>0) return true;
    return false;
}

void dfs1(ll u, ll p)
{
    mx[u][0]=d[u];
    for (auto [v, w, id]: adj[u]) if (v!=p)
    {
        par[v][0]=u;
        dfs1(v, u);
    }
}

void dfs(ll u, ll p=0, ll dist=0)
{
    timein[u]=++timedfs;
    sub[u]=d[u];
    distances[u]=dist;
    if (d[u]==1) dp[u]=0;
    else dp[u]=1e18;
    for (auto [v, w, id]: adj[u]) if (v!=p)
    {
        dfs(v, u, dist+w);
        sub[u]+=sub[v];
        dx[v]=dx[u]+1;
        dp[u]=min(dp[u], dp[v]+w);
        for (auto [x, i]: queries[id])
        {
            if (!(timein[v]<=timein[x] && timeout[x]<=timeout[v])) res[i]="escaped";
            else if (sub[v]==0) res[i]="oo";
            else 
            {
                ll ans1=dp[x];
                ll ans2=1e18;
                ll answer=0;
                ll dd=dx[x]-dx[v];
                for (ll j=18; j>=0; j--) if (dd&(1LL<<i)) if (mx[x][j]==1)
                {
                    x=par[x][j];
                    answer+=(1LL<<j);
                }
                ans2=distances[x+dd]-distances[answer];
                ll ans3=dp[v]+distances[x]-distances[v];
                res[i]=to_string(min({ans1, ans2, ans3}));
            }
        }
    }
    timeout[u]=timedfs;
}

void solve()
{
    cin>>n>>m>>q>>s;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }
    for (ll i=1; i<=m; i++) 
    {
        ll x; cin>>x;
        d[x]=1;
    }
    dfs1(s, 0);
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=18; j++) 
            par[i][j]=par[par[i][j-1]][j-1];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=18; j++)
            mx[i][j]=max(mx[i][j-1], mx[par[i][j-1]][j-1]);
    for (ll i=1; i<=q; i++)
    {
        ll id, x; cin>>id>>x;
        queries[id].push_back({x, i});
    }
    dfs(s);
    // for (ll i=1; i<=n; i++) cout<<timein[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<timeout[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<sub[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=3; j++) cout<<mx[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for (ll i=1; i<=q; i++) cout<<res[i]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}