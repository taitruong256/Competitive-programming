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
    ll n, k; cin>>n>>k;
    ll a[n+5], pos[n+5], ans[n+5];
    for (ll i=1; i<=n; i++) a[i]=1e10;
    for (ll i=1; i<=n; i++) ans[i]=1e10;
    for (ll i=1; i<=k; i++) cin>>pos[i];
    for (ll i=1; i<=k; i++) cin>>a[pos[i]];
    // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;

    ll mn=1e10;
    for (ll i=1; i<=n; i++) 
    {
        if (a[i]<mn) mn=a[i];
        ans[i]=min(ans[i], mn);
        ++mn;
    }
    mn=1e10;
    for (ll i=n; i>=1; i--) 
    {
        if (a[i]<mn) mn=a[i];
        ans[i]=min(ans[i], mn);
        ++mn;
    }
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
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