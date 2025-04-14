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
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll s1=0, s2=0;
    sort(a+1, a+n+1, greater<ll>());
    for (ll i=1; i<=n; i+=2) s1+=a[i], s2+=a[i+1];
    if (s1>s2) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    for (ll _=0; _<t; _++) solve();
    return 0;
}