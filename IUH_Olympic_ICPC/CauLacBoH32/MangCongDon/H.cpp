/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
void solve()
{
    ll n; cin>>n;
    ll vao[n+5], ra[n+5], pos[n+5], tg_ra[n+5];
    for (ll i=1; i<=n; i++) cin>>vao[i];
    for (ll i=1; i<=n; i++) cin>>ra[i];
    for (ll i=1; i<=n; i++) pos[ra[i]]=i;
    for (ll i=1; i<=n; i++) tg_ra[i]=pos[vao[i]];
    ll ans=0, mx=-1e18;
    for (ll i=1; i<=n; i++) 
    {
        if (tg_ra[i]>mx) mx=tg_ra[i];
        else ++ans;
    }
    cout<<ans;  
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