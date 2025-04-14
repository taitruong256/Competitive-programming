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

void solve()
{
    ll n, m; cin>>n>>m;
    vector<bool> visited(n+5, false);
    for (ll i=0; i<m; i++)
    {
        ll u, v; cin>>u>>v;
        visited[u]=visited[v]=true;
    }
    ll opt=1;
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        opt=i;
        break;
    }
    cout<<n-1<<endl;
    for (ll i=1; i<=n; i++) if (i!=opt) cout<<opt<<" "<<i<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}