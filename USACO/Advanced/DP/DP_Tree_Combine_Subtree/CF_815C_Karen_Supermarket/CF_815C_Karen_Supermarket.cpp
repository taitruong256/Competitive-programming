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
const ll mod = 1e9+7;

ll n, lim, c[5005], d[5005], dp[5005][2][5005], sz[5005];
vector<ll> adj[5005];

void dfs(ll u, ll p)
{
    dp[u][0][0]=0;
    dp[u][0][1]=c[u];
    dp[u][1][1]=c[u]-d[u];
    sz[u]=1;
    for (ll v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        for (ll i=sz[u]; i>=0; i--)      //luu y chay tu sz[u] den 0 hoac gan vao mang tam
            for (ll j=0; j<=sz[v]; j++)  //giong thu cai tui 1 dung mang 1 chieu
            {                            //vi neu khong thi cac gia tri sau bi thay doi khong dung 
                dp[u][0][i+j]=min(dp[u][0][i+j], dp[u][0][i]+dp[v][0][j]);
                dp[u][1][i+j]=min(dp[u][1][i+j], dp[u][1][i]+min(dp[v][1][j], dp[v][0][j]));
            }
        sz[u]+=sz[v];
    }
}

void solve()
{
    cin>>n>>lim;
    for (ll i=0; i<=n; i++) 
        for (ll j=0; j<=n; j++) 
            dp[i][0][j]=dp[i][1][j]=1e18;
    for (ll i=1; i<=n; i++)
    {
        cin>>c[i]>>d[i];
        if (i>1)
        {
            ll x; cin>>x;
            adj[x].push_back(i);
        }
    }
    dfs(1, 0);
    ll ans=0;
    for (ll i=1; i<=n; i++) if (min(dp[1][0][i], dp[1][1][i])<=lim) ans=max(ans, i);
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