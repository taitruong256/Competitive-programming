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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll maxn = 2e5+5;
vector<ll> adj[maxn], color, cnt;
ll n;

bool bfs(ll u)
{
    queue<ll> q;
    q.push(u);
    color[u]=1;
    while (!q.empty())
    {
        u=q.front(); q.pop();
        for (auto v: adj[u]) 
            if (color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if (color[u]==color[v]) return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) adj[i].clear();
    color.resize(0); color.resize(n+5, -1);
    cnt.resize(0); cnt.resize(n+5, 0);
    for (ll i=0; i<n; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++cnt[u];
        ++cnt[v];
    }
    for (ll i=1; i<=n; i++) if (cnt[i]!=2)
    {
        cout<<"NO\n";
        return;
    }
    for (ll i=1; i<=n; i++)
        if (color[i]==-1)
        {
            if (bfs(i)==false) 
            {
                cout<<"NO\n";
                return;
            }
        }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}