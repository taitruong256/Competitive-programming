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
ll n, q, depth[200005], time_in[200005], time_out[200005], timer;
vector<vector<ll>> adj(200005), d(200005);

void dfs(ll u, ll par=0)
{
    time_in[u]=++timer;
    depth[u]=depth[par]+1;
    d[depth[u]].push_back(time_in[u]);
    for (auto v: adj[u]) if (v!=par) dfs(v, u);
    time_out[u]=timer;
}

void solve()
{
    cin>>n;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    depth[0]=-1;
    dfs(1);
    cin>>q;
    while (q--)
    {
        ll u, h; cin>>u>>h;
        cout<<upper_bound(d[h].begin(), d[h].end(), time_out[u])-lower_bound(d[h].begin(), d[h].end(), time_in[u])<<endl;
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