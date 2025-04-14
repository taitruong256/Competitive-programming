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
    ll a[n+5], b[n+5];
    ll ans=1e18;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        memset(b, 0, sizeof(b));
        ll cnt=0;
        ll x=0;
        for (ll j=i-1; j>=1; j--)
        {   
            x=((x/a[j])*a[j]+a[j]);
            cnt+=x/a[j];   // cout<<x<<" ";
        }
        x=0;                 //   cout<<0<<" "; 
        for (ll j=i+1; j<=n; j++)
        {
            x=((x/a[j])*a[j]+a[j]);
            cnt+=x/a[j];   // cout<<x<<" ";
        }                    //   cout<<endl;
        ans=min(ans, cnt);
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
    solve();
    return 0;
}