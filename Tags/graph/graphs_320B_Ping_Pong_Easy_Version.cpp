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
ll n, a[105], b[105];
bool visited[105];

void dfs(ll u)
{
    visited[u]=true;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        if (a[i]<a[u] && a[u]<b[i]) dfs(i);
        else if (a[i]<b[u] && b[u]<b[i]) dfs(i);
    }
}

void solve()
{
    ll t; cin>>t;
    n=0;
    while (t--)
    {
        ll m, x, y; cin>>m>>x>>y;
        if (m==1)
        {
            ++n;
            a[n]=x;
            b[n]=y;
        }
        else 
        {
            memset(visited, false, sizeof(visited));
            dfs(x);
            if (visited[y]==true) cout<<"YES\n";
            else cout<<"NO\n";
        }
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