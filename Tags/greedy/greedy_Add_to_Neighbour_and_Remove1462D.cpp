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
    ll sum=0;
    for (ll i=1; i<=n; i++) sum+=a[i];
    
    for (ll k=1; k<=n; k--) if (sum%k==0)
    {
        ll s=0;
        ll sumk=sum/k;
        bool ok=true;
        for (ll j=1; j<=n; j++)
        {
            s+=a[j];
            if (s>sumk)
            {
                ok=false;
                break;
            }
            else if (s==sumk) s=0;
        }

        if (ok==true) 
        {
            cout<<n-k<<endl;
            return;
        }
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