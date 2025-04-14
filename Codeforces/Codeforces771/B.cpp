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
    ll a[n+5], chan[n+5], le[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll cnt1=0, cnt2=0;
    for (ll i=0; i<n; i++) if (a[i]%2==0) chan[cnt1++]=a[i]; else le[cnt2++]=a[i];
    if (is_sorted(chan, chan+cnt1) && is_sorted(le, le+cnt2)) cout<<"Yes\n";
    else cout<<"No\n";
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