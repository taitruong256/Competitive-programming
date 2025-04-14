/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
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
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m; 
vector<ll> adj[100005];
pair<ll, ll> a[100005];
ll b[100005];

void solve()
{
    ll n, x; cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>x, a[i]={x, i};
    for (ll i=0; i<=n; i++) adj[i].clear();
    for (ll i=1; i<=n; i++) b[i]=a[i].first;
    
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool choose[n+5];
    memset(choose, true, sizeof(choose));
    // for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl; cout<<endl;
    sort(a+1, a+n+1, greater<pair<ll, ll>>());
    // for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl; cout<<endl;
    for (ll i=1; i<=n; i++) if (choose[a[i].second]==true)
    {
        choose[a[i].second]=true;  // cout<<a[i].second<<endl;
        for (auto j: adj[a[i].second]) 
        {
            choose[j]=false;
            break;
        }
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) if (choose[i]==false) ans+=b[i];
    cout<<ans<<endl;
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