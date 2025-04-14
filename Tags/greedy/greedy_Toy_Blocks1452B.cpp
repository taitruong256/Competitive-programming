#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{
    ll n; cin>>n;
    ll sum=0, mx=0;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        sum+=x;
        mx=max(mx, x);
    }
    ll ans=max(mx, ((sum+n-2)/(n-1)));    
    cout<<ans*(n-1)-sum<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}