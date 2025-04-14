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
    ll n; cin>>n;
    ll f[n+5][4], a[n+5];
    for (ll i=1 ;i<=n; i++) cin>>a[i];
    memset(f, -1e9, sizeof(f));
    f[0][0]=0;
    for (ll i=1; i<=n; i++)
    {
        f[i][0]=max({f[i-1][1], f[i-1][2], f[i-1][0]});
        if (a[i]==1 || a[i]==3) f[i][1]=max(f[i-1][0], f[i-1][2])+1;
        if (a[i]==2 || a[i]==3) f[i][2]=max(f[i-1][0], f[i-1][1])+1;
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<3; j++) cout<<f[i][j]<<" "; cout<<endl;
    }
    cout<<n-max({f[n][0], f[n][1], f[n][2]});
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