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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, deg[300005], dp[300005][30];
char c[300005];
vector<ll> adj[300005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>c[i];
    while (m--)
    {
      ll u, v; cin>>u>>v;
      adj[u].push_back(v);
      deg[v]++;
    }
    queue<ll> q;
    for (ll i=1; i<=n; i++) if (deg[i]==0) q.push(i);
    ll cnt=0;
    while (!q.empty())
    {
      ++cnt;  
      ll u=q.front(); q.pop(); 
      ++dp[u][c[u]-'a'+1];
      for (ll v: adj[u])
      {
        for (ll i=1; i<=26; i++) dp[v][i]=max(dp[v][i], dp[u][i]);
        --deg[v];
        if (deg[v]==0) q.push(v);
      }
    }
    if (cnt<n)
    {
      cout<<-1;
      return;
    }
    ll ans=0;
    for (ll i=1; i<=n; i++)
      for (ll j=1; j<=26; j++) ans=max(ans, dp[i][j]);
    cout<<ans;
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