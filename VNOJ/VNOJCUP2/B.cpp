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
ll n, m, k;
ll a[100005][15], tong[100005][15];
ll ans=0;
map<pair<ll, ll>, ll> dp;

ll doiqua(ll hang, ll soluong)
{           
    if (hang<1 || soluong==0) return 0;
    if (dp[{hang, soluong}]) return dp[{hang, soluong}];
    ll tam=-1e9;
    for (ll x=0; x<=m; x++) if (x<=soluong)
    {
        tam=max(tam, doiqua(hang-1, soluong-x)+tong[hang][x]);
    }       
    dp[{hang, soluong}]=tam;      //     cout<<hang<<" "<<soluong<<" "<<" "<<dp[{hang, soluong}]<<endl;
    return tam;
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    for (ll i=1; i<=n; i++) tong[i][0]=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) tong[i][j]=tong[i][j-1]+a[i][j];
    cout<<doiqua(n, k);
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