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
ll n, q; 
ll parent[200005][21];

void solve()
{
    cin>>n>>q;
    memset(parent, 0, sizeof(parent));
    for (ll i=2; i<=n; i++) cin>>parent[i][0];

    for (ll j=1; j<21; j++)
        for (ll i=1; i<=n; i++) parent[i][j]=parent[parent[i][j-1]][j-1];
    
    while (q--)
    {
        ll x, k; cin>>x>>k;
        for (ll i=0; i<21; i++) if (k&(1<<i)) x=parent[x][i];
        if (x==0) cout<<-1<<endl; else cout<<x<<endl;
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