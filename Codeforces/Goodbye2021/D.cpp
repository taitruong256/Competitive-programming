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
    ll a[n+1];
    double sum[n+1]={0};
    ll ans=1;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    bool check=true;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=n; j++) if (sum[i]-sum[j]!=0.5*(a[i]+a[j])*(j-i+1)) 
        {
            check=false;
            if (check==false) break;
        }
        if (check==false) break;
    }
    if (check==true)
    { 
        cout<<0<<endl;
        return;
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=i+1; j<=n; j++) if (a[j]>a[i])
        {
            ll now=2;
            ll d=a[j]-a[i], last=a[j];    
            for (ll k=j+1; k<=n; k++) if (a[k]==last+d)
            {                 //printf("i = %d, j = %d, k = %d, now = %d", i, j, k, now);
                ++now;
                last=a[k];
            }
            ans=max(ans, now);
        }
        
    }
    cout<<n-ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                 cin>>t;
    while (t--) solve();
    return 0;
}