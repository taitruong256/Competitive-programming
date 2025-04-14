/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                   You may not be the best, but be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll a, b, c; cin>>a>>b>>c;
    ll m=a*b*c;
    ll prime[m+5];
    memset(prime, 0, sizeof(prime));
    for (ll i=1; i<=m; i++)
        for (ll j=i; j<=m; j+=i) prime[j]++;
    
    ll ans=0, mod=1073741824;
    for (ll i=1; i<=a; i++)
        for (ll j=1; j<=b; j++)
            for (ll k=1; k<=c; k++) ans=(ans+prime[i*j*k])%mod;
    cout<<ans;
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