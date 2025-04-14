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

void solve()
{
    ll n; cin>>n;
    ll a[n+5][n+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            char c; cin>>c;
            a[i][j]=c-'0';
        }
    
    ll ans=0;
    for (ll i=1; i<=(n+1)/2; i++)
        for (ll j=i; j<=n-i; j++)
        {
            // printf("(%lld, %lld) (%lld, %lld) (%lld, %lld) (%lld, %lld)\n", i, j, n-i+1, n-j+1, i, n-j+1, j, n-i+1);
            ll sum=0;
            // cout<<a[i][j]<<" "<<a[n-i+1][n-j+1]<<" "<<a[i][n-j+1]<<" "<<a[j][n-i+1]<<" "<<endl;
            sum=a[i][j]+a[n-i+1][n-j+1]+a[n-j+1][i]+a[j][n-i+1];    // cout<<sum<<endl;
            ans+=min(sum, 4-sum);
        }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}