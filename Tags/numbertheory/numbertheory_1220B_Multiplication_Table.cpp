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

void solve()
{
    ll n; cin>>n;
    ll a[n+5][n+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];
    
    ll ans[n+5];
    ans[1]=(ll)sqrt((a[1][2]*a[1][3])/a[2][3]);
    for (ll i=2; i<=n; i++) ans[i]=a[1][i]/ans[1];
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
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