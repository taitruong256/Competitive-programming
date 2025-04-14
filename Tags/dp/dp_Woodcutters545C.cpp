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
    ll x[n+5], h[n+5], f[n+5];
    for (ll i=1; i<=n; i++) cin>>x[i]>>h[i];

    f[0]=0;
    f[1]=1;
    ll last=x[1];
    for (ll i=2; i<n; i++) 
    {
        ll l=x[i]-h[i], r=x[i]+h[i];
        if (l>last)
        {
            f[i]=f[i-1]+1;
            last=x[i];
        }
        else if (r<x[i+1])
        {
            f[i]=f[i-1]+1;
            last=r;
        }
        else
        {
            f[i]=f[i-1];
            last=x[i];
        }
    }
    f[n]=f[n-1]+1;
    cout<<f[n];
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