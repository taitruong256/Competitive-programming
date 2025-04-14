/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tohop[1005][1005];
ll mod=1e9+7;

void solve()
{
    ll n; cin>>n;
    ll ans=1, sum=0;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        ans=(ans*tohop[sum+x-1][x-1])%mod;
        sum+=x;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    tohop[0][0]=1;
    for (ll i=1; i<=1000; i++)
    {
        tohop[i][0]=1;
        for (ll j=1; j<=i; j++) tohop[i][j]=(tohop[i-1][j]+tohop[i-1][j-1])%mod;
    }
    solve();
    return 0;
}