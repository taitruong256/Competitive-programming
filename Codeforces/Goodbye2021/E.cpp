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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll res=1e9;

    for(ll i = 1; i <= n; i++) 
    {
        for(ll j = i+1; j <= n; j++) 
        {
            ll num = 0;
            float d = 1.0*(a[j]-a[i]) / (j-i);
            for(ll k = 1; k <= n; k++) 
            {
                if(k <= i) 
                {
                    if(abs(a[i]-a[k]-(i-k)*d) > 0.000001) num++;
                } 
                else 
                {
                    if(abs(a[k]-a[i]-(k-i)*d) > 0.000001) num++;
                }
            }
        res = min(res, num);
        }
    }

    if(n == 1) res = 0;
    cout<<res<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}