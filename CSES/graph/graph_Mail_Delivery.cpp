/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m; 
set<ll> adj[100005];
vector<ll> degree, path;

void euler_cycle(ll s)
{
    stack<ll> st;
    st.push(s);
    while (!st.empty())
    {
        ll x=st.top(); 
        if (adj[x].size()!=0)
        {
            ll y=*adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else
        {
            path.push_back(x);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
}

void solve()
{
    cin>>n>>m;
    degree.resize(0); degree.resize(n+5, 0);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        ++degree[u];
        ++degree[v];
    }

    for (ll i=1; i<=n; i++) if (degree[i]%2==1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    euler_cycle(1);
    if (path.size()!=m+1)
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    for (auto it: path) cout<<it<<" "; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}