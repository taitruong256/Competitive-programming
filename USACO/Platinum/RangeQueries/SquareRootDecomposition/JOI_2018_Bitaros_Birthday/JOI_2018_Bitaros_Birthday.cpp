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
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
ll n, m, q, dp[100005], sq=330, qry[100005], vis[100005];  
//lưu ý là bộ nhớ n*sqrt(n) rất lớn nên
//đặt hằng số sq=200 hoặc để kiểu int thay kiểu long long sẽ giảm bộ nhớ 2 lần sẽ không bị memory limited
vector<ll> adj[100005];
vector<pair<ll, ll>> d[100005];
 
void solve()
{
    cin>>n>>m>>q;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[v].push_back(u);
    }
    for (ll i=1; i<=n; i++)
    {
        vector<ll> candidates;
        for (ll u: adj[i]) 
        {
            for (auto [w, x]: d[u])
            {
                if (vis[x]!=i)
                {
                    candidates.push_back(x);
                    dp[x]=w+1;
                    vis[x]=i;
                }
                else dp[x]=max(dp[x], w+1);
            }
        }
        candidates.push_back(i);
        dp[i]=0;
        vector<pair<ll, ll>> dist;
        for (auto u: candidates) dist.push_back({dp[u], u});
        sort(dist.begin(), dist.end(), greater<pair<ll, ll>>());
        for (ll j=0; j<min((ll)dist.size(), sq); j++) d[i].push_back(dist[j]);
    }
 
    for (ll k=1; k<=q; k++)
    {
        ll z; cin>>z;
        ll cnt; cin>>cnt;
        for (ll i=0; i<cnt; i++)
        {
            ll x; cin>>x;
            qry[x]=k;
        }
        if (cnt<sq)
        {
            ll ans=-1;
            for (auto [w, v]: d[z]) if (qry[v]!=k)
            {
                ans=w;
                break;
            }
            cout<<ans<<endl;
        }
        else 
        {
            for (ll i=1; i<=n; i++) dp[i]=-1;
            for (ll i=1; i<=n; i++) if (qry[i]!=k) 
                dp[i]=0;
            for (ll i=1; i<=n; i++) 
                for (ll v: adj[i]) if (dp[v]!=-1) dp[i]=max(dp[i], dp[v]+1);
            cout<<dp[z]<<endl;
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