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
ll sz[505], par[505];
set<ll> adj[505];

void dfs(ll u, ll p)
{
    sz[u]=1;
    par[u]=p;
    for (auto v: adj[u]) if (v!=p) 
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void solve()
{
    ll n, q; cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u=i, v=i+1;
        adj[u].insert(v);
        adj[v].insert(u);
        cout<<u<<" "<<v<<endl;
    }
    while (q--)
    {
        ll d; cin>>d;
        if (d==n-1)
        {
            ll u=-1, v=-1, w=-1;
            for (ll i=1; i<=n; i++) if (adj[i].size()==3) u=i;
            if (u==-1) 
            {
                cout<<-1<<" "<<-1<<" "<<-1<<endl;
                return;
            }
            dfs(u, u);
            ll v=-1;                                             // u la dinh co bac 3
            for (auto i: adj[u]) if (v==-1 || sz[i]>sz[v]) v=i;  // tim v co sz lon nhat 
            for (ll i=1; i<=n; i++) if (adj[i].size()==1) w=i;   // w la la
            adj[u].erase(v);
            adj[v].erase(u);
            adj[u].insert(w);
            adj[w].insert(u);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
        else 
        {
            
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}