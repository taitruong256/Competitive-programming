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
ll n; 
ll a[100005]={0}, b[100005]={0};

bool check(ll x)
{
    ll use=(n+x)-(n+x)/4;
    ll suma, sumb;
    if (use>=x) suma=x*100+a[use-x]; else suma=x*100;
    sumb=b[min(n, use)];    
    return suma>=sumb; 
}
void solve()
{
    cin>>n;
    
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    sort(a+1, a+1+n, greater<ll>());
    sort(b+1, b+1+n, greater<ll>());
    for (ll i=1; i<=n; i++) a[i]=a[i]+a[i-1];
    for (ll i=1; i<=n; i++) b[i]=b[i]+b[i-1];

    ll l=0, r=1e9, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
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