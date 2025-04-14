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
vector<ll> adj[maxn];
bool vis[maxn];
ll n, a[maxn], b[maxn], ans[maxn], sa, sb;
vector<ll> sum;

void dfs(ll u)
{
    vis[u]=true;
    sa+=a[u];
    sb+=b[u];
    sum.push_back(sb);    //cout<<u<<"       "; for (auto i: sum) cout<<i<<" "; cout<<endl;
    ans[u]=upper_bound(sum.begin(), sum.end(), sa)-sum.begin()-1;
    for (auto v: adj[u]) if (vis[v]==false) dfs(v);
    sa-=a[u];
    sb-=b[u];
    sum.pop_back();
}

void solve()
{
    cin>>n;
    a[1]=b[1]=sa=sb=0;
    for (ll i=1; i<=n; i++) adj[i].clear();
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p>>a[i]>>b[i];
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    for (ll i=1; i<=n; i++) vis[i]=false;
    dfs(1);
    for (ll i=2; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}