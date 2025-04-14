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
    ll s=0;
    for (ll i=1; i<=n; i++) s+=a[i];

    ll sum[2]={0, 0};
    for (ll i=1; i<=n; i++) sum[i%2]+=a[i]-1;
    
    if (2*sum[0]<=s)
    {
        for (ll i=1; i<=n; i++) 
            if (i%2==0) cout<<1<<" ";
            else cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    else
    {
        for (ll i=1; i<=n; i++) 
            if (i%2==1) cout<<1<<" ";
            else cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
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