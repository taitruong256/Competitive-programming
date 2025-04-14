/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[1005];

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5], c[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>c[i];
    ll s=0;
    for (ll i=1; i<=n; i++) s+=w[a[i]];
    k=min(k, s);
    ll f[n+5][k+5];
    memset(f, 0, sizeof(f));
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<=k; j++) 
            if (j>=w[a[i]]) f[i][j]=max(f[i-1][j], f[i-1][j-w[a[i]]]+c[i]);
            else f[i][j]=f[i-1][j];

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=k; j++) cout<<f[i][j]<<" "; 
    //     cout<<endl;
    // }

    cout<<f[n][k]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif

    for (ll i=0; i<1005; i++) w[i]=1e9;
    w[1]=0;
    for (ll i=1; i<1005; i++)
        for (ll j=1; j<=i; j++)
            if (i+i/j<1005) w[i+i/j]=min(w[i+i/j], w[i]+1);

    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}