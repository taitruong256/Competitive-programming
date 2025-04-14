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
    ll a[n+5], ans[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll m=1;
    ll prime[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    memset(ans, -1, sizeof(ans));
    for (ll i=0; i<11; i++)
    {
        bool ok=false;
        for (ll j=1; j<=n; j++) if (a[j]%prime[i]==0 && ans[j]==-1) 
        {
            ans[j]=m;
            ok=true;
        }
        if (ok==true) ++m;
    }

    cout<<m-1<<endl;
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
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