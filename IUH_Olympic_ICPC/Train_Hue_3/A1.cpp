/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visited[1005][1005];
set<pair<ll, ll>> thoaimai;

ll cnt(ll x, ll y)
{
    if (x<0 || y<0 || visited[x][y]==true) return 0;
    ll cnt=0;
    if (visited[x][y-1]==true) ++cnt; 
    if (visited[x][y+1]==true) ++cnt; 
    if (visited[x-1][y]==true) ++cnt; 
    if (visited[x+1][y]==true) ++cnt; 
}

void solve()
{
    memset(visited, false, sizeof(visited));
    ll n; cin>>n;

    for (ll i=0; i<n; i++)
    {
        ll u, v; cin>>u>>v;
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