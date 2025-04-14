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
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll ans=1e18;
    for (ll i=0; i<=3; i++)
    {
        ll one=0, two=0, mx=*max_element(a, a+n);
        for (ll j=0; j<n; j++)
        {
            one+=(mx+i-a[j])%2;
            two+=(mx+i-a[j])/2;
        }
        ll all=one+two*2;   // cout<<all<<" "<<one<<" "<<two<<endl;
        ll need=all/3*2+all%3;     
        ans=min(ans, max(one*2-1, need));
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
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}