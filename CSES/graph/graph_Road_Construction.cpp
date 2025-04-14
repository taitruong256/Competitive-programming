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
ll n, m, tplt, mx;
vector<ll> parent, size;

ll find(ll u)
{
    if (parent[u]==u) return u;
    return parent[u]=find(parent[u]);
}

void merge(ll u, ll v, ll &tplt, ll &mx)
{
    u=find(u);   
    v=find(v); 
    if (u==v) return;
    --tplt;
    if (size[u]<size[v]) swap(u, v);
    parent[v]=u;
    size[u]+=size[v];
    mx=max(mx, size[u]);  //    for (ll i=1; i<=n; i++) cout<<parent[i]<<" "; cout<<endl<<endl;
}

void solve()
{
    cin>>n>>m;
    parent.resize(0); parent.resize(n+5);
    size.resize(0); size.resize(n+5, 1);
    for (ll i=1; i<=n; i++) parent[i]=i;
    ll tplt=n, mx=0;
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        merge(u, v, tplt, mx);
        cout<<tplt<<" "<<mx<<endl;
    }
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