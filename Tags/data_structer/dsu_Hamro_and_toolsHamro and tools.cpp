/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n, m;
ll parent[100005];

ll root(ll v)
{
    if (parent<0) return v;
    return (parent[v]=root(parent[v]));
}

void merge(ll x, ll y)
{
    if (parent[x]==parent[y]) return;
    if (parent[x]>parent[y]) swap(x, y);
    parent[x]+=parent[y];
    parent[y]=x;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) parent[i]=-1;
    for (ll i=1; i<=m; i++)
    {
        ll s, t; cin>>s>>t;
        merge(s, t);
    }
    for (ll i=1; i<=n; i++) cout<<-parent[i]<<" "; cout<<endl;
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