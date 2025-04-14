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
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    ll ans=1e18;
    for (ll i=1; i<=100000; i++)
    {
        ll curpow=1, cnt=0;
        for (ll j=0; j<n; j++) 
        {
            cnt+=abs(a[j]-curpow);
            curpow*=i;
            if (curpow>1e18) break;
        }
        if (curpow>1e18) break;
        ans=min(ans, cnt);
        if (cnt>ans) break;
    }
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