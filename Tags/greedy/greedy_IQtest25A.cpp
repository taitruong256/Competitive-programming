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
    ll cnt[n+5], last[n+5];
    memset(cnt, 0, sizeof(cnt));
    for (ll i=0; i<n; i++)
    {
        last[a[i]%2]=i+1;
        cnt[a[i]%2]++;
    }        // cout<<cnt[0]<<" "<<cnt[1]<<endl;
    if (cnt[0]==1) cout<<last[0]; else cout<<last[1];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    while (t--) solve();
    return 0;
}