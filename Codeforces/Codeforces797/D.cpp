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
    ll n, k; cin>>n>>k;
    ll dem[n+5];
    memset(dem, 0, sizeof(dem));
    string s; cin>>s;
    for (ll i=0; i<s.size(); i++) 
        if (s[i]=='W') dem[i+1]=dem[i]+1;
        else  dem[i+1]=dem[i];
    ll ans=1e9;
    for (ll i=k; i<=n; i++) 
    {
        ans=min(ans, dem[i]-dem[i-k]);
        
    }
    // for (ll i=1; i<=n; i++) cout<<dem[i]<<" "; cout<<endl;
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