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
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

ll n, isfile[100005], len[100005], dp[100005], sub[100005], ans=inf;
vector<ll> adj[100005];

void dfs(ll u)
{
    if (isfile[u]==1)
    {
        sub[u]=1;
        dp[u]=0;
        return;
    }
    for (ll v: adj[u])
    {
        dfs(v);
        sub[u]+=sub[v]; 
        dp[u]+=dp[v]+(len[v]+!isfile[v])*sub[v];   
    }
}

void reroot(ll u)
{
    ans=min(ans, dp[u]);
    for (auto v: adj[u])
    {
        if (isfile[v]==1) continue;
        dp[u]-=dp[v]+(len[v]+1)*sub[v];
        sub[u]-=sub[v];
        dp[v]+=dp[u]+3*sub[u];
        sub[v]+=sub[u];
        reroot(v);
        sub[v]-=sub[u];
        dp[v]-=dp[u]+3*sub[u];
        sub[u]+=sub[v];
        dp[u]+=dp[v]+(len[v]+1)*sub[v];
    }
}

void solve()
{
    setIO("dirtraverse");
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        string s; cin>>s;
        len[i]=s.size();
        ll k; cin>>k;
        if (k==0) isfile[i]=1;
        else 
        {
            isfile[i]=0;
            for (ll j=0; j<k; j++) 
            {
                ll x; cin>>x;
                adj[i].push_back(x);
            }
        }
    }
    dfs(1);
    reroot(1);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}