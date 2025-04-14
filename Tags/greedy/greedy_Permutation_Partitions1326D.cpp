/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll ans=1, sum=0, last=-1;
    for (ll i=1; i<=n; i++)
    {                          
        if (a[i]>=n-k+1) 
        {
            sum+=a[i];            
            if (last!=-1) ans=( (ans%mod)*(i-last)%mod  )%mod;  
            last=i;  
        }    
    }                 
    cout<<sum<<" "<<ans<<endl;
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