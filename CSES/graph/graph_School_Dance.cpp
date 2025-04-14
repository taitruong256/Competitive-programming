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
const ll mod = 1e9+7;
ll n, m, k;
vector<ll> adj[505], mt;
vector<bool> used;

bool kuhn(ll u)
{
    if (used[u]==true) return false;
    used[u]=true;
    for (auto v: adj[u]) 
    {
        if (mt[v]==-1 || kuhn(mt[v])==true)
        {
            mt[v]=u;
            return true;
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=0; i<k; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
    }

    mt.assign(k+5, -1);
    for (ll i=1; i<=n; i++)
    {
        used.assign(505, false);
        kuhn(i);
    }

    vector<pair<ll, ll>> ans;
    for (ll i=1; i<=m; i++) if (mt[i]!=-1) ans.push_back({mt[i], i});
    cout<<ans.size()<<endl;
    for (auto [u, v]: ans) cout<<u<<" "<<v<<endl;
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