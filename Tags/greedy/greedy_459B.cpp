/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);         
    ll d1=0, d2=0;
    if (a[0]==a[n-1])
    {
        cout<<0<<" "<<(n-1)*n/2;
        return;
    }
    for (ll i=0; i<n; i++)
    {
        if (a[i]==a[0]) ++d1;
        else break;
    }
    for (ll i=n-1; i>=0; i--)
    {           
        if (a[i]==a[n-1]) ++d2;
        else break;
    }    
    cout<<a[n-1]-a[0]<<" "<<d1*d2;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; // cin>>t;
    while (t--) solve();
    return 0;
}