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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll par[1005], sz[1005];
ll has_edge[1005][1005];

ll find(ll u)
{
    if (u==par[u]) return u;
    return par[u]=find(par[u]);   //neu co rollback thi return find(par[u]);
}
    
bool merge(ll u, ll v)
{
    u=find(u);
    v=find(v);
    if (u==v) return false;
    if (sz[u]<sz[v]) swap(u, v);
    par[v]=u;
    sz[u]+=sz[v];
    return true;
}

bool same_component(ll u, ll v)
{
    return find(u)==find(v);
}

ll query(ll a, ll b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    ll x; cin>>x;
    return x;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) par[i]=i, sz[i]=1;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
            has_edge[i][j]=0;
    deque<pair<ll, ll>> edge, candidates;
    ll num_query=0;
    for (ll i=2; i<=n; i++) candidates.push_back({1, i});
    while (sz[find(1)]<n && !candidates.empty())
    {
        auto [x, y]=candidates.front(); candidates.pop_front();
        if (same_component(x, y)==true) continue;
        ll mid=query(x, y);
        ++num_query;
        assert(num_query<=15*n);
        if (mid==x) 
        {
            merge(x, y);
            edge.push_back({x, y});
            has_edge[x][y]=1;
        }
        if (same_component(x, mid)==false) candidates.push_back({x, mid});
        if (same_component(mid, y)==false) candidates.push_back({mid, y});
    }
    cout<<"! ";
    for (auto [x, y]: edge) cout<<x<<" "<<y<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}