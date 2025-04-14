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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, dp[100005], s[100005], v[100005];
vector<pair<ll, ll>> adj[100005];
struct Line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
    ld intersect(const Line &other) {return 1.0*(other.b-b)/(a-other.a);}
};
Line hull[100005];
ll sz=0;

ll query(ll x)
{
    ll l=0, r=sz-2, ans=sz-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (x<hull[mid].intersect(hull[mid+1])) ans=mid, r=mid-1;
        else l=mid+1;
    }
    return hull[ans].get(x);
}

ll remove_pos(Line line)
{
    if (sz<2 || hull[sz-1].intersect(line)>=hull[sz-1].intersect(hull[sz-2])) return sz;
    ll l=0, r=sz-2, ans=sz-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (line.intersect(hull[mid])<hull[mid].intersect(hull[mid+1])) ans=mid, r=mid-1;
        else l=mid+1;
    }
    return ans+1;
}

void dfs(ll u, ll p, ll d)
{
    ll pre_sz, pre_pos;
    Line pre_line;
    if (u==1) 
    {
        hull[sz++]={0, 0};   
        dp[u]=0;       
    }
    else 
    {
        dp[u]=query(v[u])+d*v[u]+s[u];  
        pre_sz=sz;                            
        pre_pos=sz=remove_pos({-d, dp[u]});
        pre_line=hull[sz];        
        hull[sz++]={-d, dp[u]};    
    }
    for (auto [v, w]: adj[u]) if (v!=p)
    {
        dfs(v, u, d+w);
    }
    if (u!=1)
    {
        sz=pre_sz;
        hull[pre_pos]=pre_line;
    }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (ll i=2; i<=n; i++) cin>>s[i]>>v[i];
    dfs(1, 0, 0);
    for (ll i=2; i<=n; i++) cout<<dp[i]<<" ";
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