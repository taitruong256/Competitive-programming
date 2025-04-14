/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    ll sum=0, xr=0;
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        sum+=a[i];
        xr^=a[i];
    }    // cout<<sum<<"    "<<xr<<endl;
    
    if (xr==sum) 
    {
        cout<<0<<endl<<endl;
        return;
    }

    // ll ans=0;
    // for (ll i=0; i<32; i++)
    // {
    //     if (sum&(1<<i)==0 && xr&(1<<i)) ans+=(1<<i);
    //     else if () 
    // }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}