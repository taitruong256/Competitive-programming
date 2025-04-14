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
ll n, k, h[200005][2], l[200005], ans=INT_MAX, dist[200005], sum[200005];
vector<pair<ll, ll>> adj[200005];
map<ll, ll> info[200005];

void prepare(ll u, ll p, ll d, ll s)
{
    info[u][s]=d;  
    dist[u]=d;
    sum[u]=s;    
    for (auto [v, w]: adj[u]) 
        if (v!=p) 
            prepare(v, u, d+1, s+w);
}

void small_to_large_merge(ll u, ll p)
{
    for (auto [v, w]: adj[u]) if (v!=p)
    {
        small_to_large_merge(v, u);
        if (info[u].size()<info[v].size()) info[u].swap(info[v]);

        for (auto [s, d]: info[v])
            if (info[u].find(k+2*sum[u]-s)!=info[u].end()) 
                ans=min(ans, info[u][k+2*sum[u]-s]+d-2*dist[u]);
        
        for (auto [s, d]: info[v])
            if (info[u].find(s)==info[u].end())
                info[u][s]=d;
            else 
                info[u][s]=min(info[u][s], d);
    }
}

ll best_path(ll n, ll k, ll h[][2], ll l[])
{
    if (k==1) return 0;
    for (ll i=0; i<n-1; i++) 
    {
        ll u=h[i][0], v=h[i][1], w=l[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prepare(0, -1, 0, 0);
    small_to_large_merge(0, -1);
    if (ans==INT_MAX) ans=-1;
    return ans;
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n-1; i++) cin>>h[i][0]>>h[i][1]>>l[i];
    cout<<best_path(n, k, h, l)<<endl;
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