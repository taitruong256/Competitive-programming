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
#define ll int
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m, deg[100005], deg2[100005];
vector<ll> adj[100005];

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) deg[i]=0;
    for (ll i=1; i<=n; i++) deg2[i]=0;
    for (auto &i: adj) i.clear();
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
        deg2[v]++;
    }
    set<pair<ll, ll>> st;
    for (ll i=1; i<=n; i++) st.insert({deg[i], i});
    vector<ll> ans;
    while (!st.empty())
    {
        pair<ll, ll> t=*st.begin();
        st.erase(t);
        ans.push_back(t.second);
        for (auto v: adj[t.second])
        {
            st.erase({deg[v], v});
            --deg[v];
            st.insert({deg[v], v});
        }
    }
    for (auto i: ans) cout<<i<<" "; cout<<endl;


    st.clear();
    ans.clear();
    for (ll i=1; i<=n; i++) st.insert({deg2[i], -i});
    while (!st.empty())
    {
        pair<ll, ll> t=*st.begin();
        st.erase(t);
        ans.push_back(-t.second);
        for (auto v: adj[-t.second])
        {
            st.erase({deg2[v], -v});
            --deg2[v];
            st.insert({deg2[v], -v});
        }
    }
    for (auto i: ans) cout<<i<<" "; cout<<endl;
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