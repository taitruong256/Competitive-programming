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
vector<ll> adj[200005], adj_t[200005];
ll n, m, cnt;
vector<ll> order, comp;
vector<bool> vis, ass;

void dfs(ll u)
{
    vis[u]=true;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
    order.push_back(u);
}

void dfs2(ll u)
{
    comp[u]=cnt;
    vis[u]=true;
    for (auto v: adj_t[u]) if (vis[v]==false) dfs2(v);
}

void solve()
{
    cin>>n>>m;
    for (ll i=0; i<n; i++)
    {
        char c1, c2;
        ll x, y;
        cin>>c1>>x>>c2>>y;
        --x; --y;
        x=(x*2)^(c1=='-');
        y=(y*2)^(c2=='-');
        ll neg_x=x^1;
        ll neg_y=y^1;
        adj[neg_x].push_back(y);
        adj[neg_y].push_back(x);
        adj_t[y].push_back(neg_x);
        adj_t[x].push_back(neg_y);
    }

    vis.assign(2*m+5, false);
    for (ll i=0; i<2*m; i++) if (vis[i]==false) dfs(i);
    reverse(order.begin(), order.end());

    vis.assign(2*m+5, false);
    comp.assign(2*m+5, -1);
    for (auto i: order) if (comp[i]==-1)
    {
        dfs2(i);
        ++cnt;
    }

    ass.assign(m+5, false);
    for (ll i=0; i<2*m; i+=2)
    {
        if (comp[i]==comp[i+1]) 
        {
            cout<<"IMPOSSIBLE";
            return;
        }
        ass[i/2]=comp[i]>comp[i+1];
    }
    for (ll i=0; i<m; i++)
        if (ass[i]==true) cout<<"+ ";
        else cout<<"- ";
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