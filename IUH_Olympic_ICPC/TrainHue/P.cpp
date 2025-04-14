/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    ll gia[n+5], trang[n+5], f[m+5];
    
    for (ll i=1; i<=n; i++) cin>>gia[i];
    for (ll i=1; i<=n; i++) cin>>trang[i];

    memset(f, 0, sizeof(f));
    for (ll i=1; i<=n; i++)
    {
        for (ll j=m; j>=gia[i]; j--) f[j]=max(f[j-gia[i]]+trang[i], f[j]);
        // for (ll j=0; j<=m; j++) cout<<f[i]<<" ";
        // cout<<endl;
    }
        
    cout<<f[m];
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