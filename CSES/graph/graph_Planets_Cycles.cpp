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
ll n;
vector<ll> adj[200005];
ll t[200005], ans[200005];
vector<bool> vis;

void cal(ll u)
{
    vis[u]=true;
    ll v=t[u];
    vector<ll> st;
    st.push_back(u);
    while (vis[v]==false) 
    {
        st.push_back(v);
        vis[v]=true;
        v=t[v];
    }
    // for (auto i: st) cout<<i<<" "; cout<<endl;

    ll val=0;
    if (ans[v]==0)
    {
        vector<ll> vi;
        while (!st.empty())
        {
            ll x=st.back();
            vi.push_back(x); st.pop_back();
            ++val;
            if (x==v) 
            {
                for (auto i: vi) ans[i]=val;
                break;
            }
        }    
    }
    else val=ans[v];

    while (!st.empty())
    {
        ans[st.back()]=++val;
        st.pop_back();
    }
}

void solve()
{
    cin>>n;
    vis.resize(0); vis.resize(n+5, false);
    memset(ans, 0, sizeof(ans));
    for (ll i=1; i<=n; i++)
    {
        cin>>t[i];
        adj[i].push_back(t[i]);
    }
    for (ll i=1; i<=n; i++) if (vis[i]==false) cal(i);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
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