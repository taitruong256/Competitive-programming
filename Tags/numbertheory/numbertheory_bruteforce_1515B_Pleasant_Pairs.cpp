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
    ll a[n+5];
    map<ll, ll> pos;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    ll ans=0;
    for (ll i=1; i<=2*n; i++)
    {
        if (pos[i]==0) continue;
        for (ll j=i+1; j*i<=2*n; j++) 
        {
            if (pos[j]==0) continue;
            if (i*j==pos[i]+pos[j]) ++ans;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}