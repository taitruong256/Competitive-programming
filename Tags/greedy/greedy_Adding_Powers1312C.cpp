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
    ll n, k; cin>>n>>k;
    ll a[n+5], b[64];
    for (ll i=1; i<=n; i++) cin>>a[i];

    memset(b, 0, sizeof(b));
    for (ll i=1; i<=n; i++)
    {
        ll j=0;
        while (a[i]>0)
        {
            b[j++]+=a[i]%k;
            a[i]/=k;
        }
    }          

    for (ll i=0; i<64; i++) if (b[i]>1)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}