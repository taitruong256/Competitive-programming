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
    ll n, l; cin>>n>>l;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    double ans=max(a[0], l-a[n-1]); 
    for (ll i=1; i<n; i++) ans=max(ans, 1.0*(a[i]-a[i-1])/2.0);
    printf("%.9lf", ans);
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}