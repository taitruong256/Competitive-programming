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
ll n, k;
vector<ll> adj[100005];
vector<pair<ll, ll>> la;   //do sau, dinh 
ll d[100005];
ll vis[100005];

void dfs(ll u)
{
    vis[u]=1;
    if (adj[u].size()==1) la.push_back({d[u], u});
    for (auto v: adj[u]) if (vis[v]==0) 
    {
        d[v]=d[u]+1;
        dfs(v);
    }
}

bool check(ll mid)
{
    for (ll i=1; i<=n; i++) vis[i]=false;
    for (ll i=0; i<mid; i++) if (la[i].second==k) return true;
    queue<ll> q;
    q.push(k);
    vis[k]=1;   //vis[u]=1 co ten trom o dinh u 
                //vis[u]=2 co bao ve o dinh u
    for (ll i=0; i<mid; i++) q.push(la[i].second), vis[la[i].second]=2;
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        if (adj[u].size()==1 && vis[u]==1) return false;
        if (vis[u]==1)
        {
            for (auto v: adj[u]) if (vis[v]==0) 
            {
                vis[v]=1;
                q.push(v);
            }
        }
        else if (vis[u]==2)
        {
            for (auto v: adj[u]) if (vis[v]!=2)
            {
                vis[v]=2;
                q.push(v);
            }
        }
    }
    return true;
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(k);
    sort(la.begin(), la.end());
    // for (ll i=1; i<=la.size(); i++) cout<<check(i)<<endl;
    ll l=1, r=la.size(), ans=la.size();
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
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