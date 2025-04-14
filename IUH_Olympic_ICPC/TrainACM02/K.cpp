/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> canh;
vector<bool> visited;
vector<ll> thutu;
set<vector<ll>> st;

void dfs(ll u)
{
    visited[u]=true;       // cout<<u<<" ";
    for (auto v: canh[u]) if (visited[v]==false) dfs(v);
    thutu.push_back(u);
}

void solve()
{
    ll n; cin>>n;
    canh.resize(0);
    canh.resize(n+5);
    st.clear();
    visited.resize(n+5, false);
    for (ll i=0; i<n-1; i++)
    {
        ll u, v; cin>>u>>v;
        canh[u].push_back(v);
        canh[v].push_back(u);
    }

    for (ll i=1; i<=n; i++) 
    {
        thutu.resize(0);
        for (ll i=1; i<=n; i++) visited[i]=false;
        dfs(i);     
        //for (auto it: thutu) cout<<it<<" "; cout<<endl;
        st.insert(thutu);
    }

    vector<ll> ans=*st.begin();
    for (auto it: ans) cout<<it<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}