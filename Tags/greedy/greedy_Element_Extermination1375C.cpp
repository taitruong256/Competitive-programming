#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
 
void solve()
{
    ll n; cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    if (a[0]<a[n-1]) cout<<"YES\n"; else cout<<"NO\n";
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}