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
    ll n; 
    double s, sum;
    cin>>n>>s;
    sum=s;
    pair<double, ll> a[n+5];
    for (ll i=1; i<=n; i++)
    {
        ll x, y, k; cin>>x>>y>>k;
        a[i].first=sqrt(x*x+y*y);
        a[i].second=k;
        sum+=k;
    }
    if (sum<1000000)
    {
        cout<<-1;
        return;
    }
    if (s>1000000)
    {
        cout<<0;
        return;
    }
    sort(a+1, a+n+1);
    a[0].second=0;
    for (ll i=1; i<=n; i++) a[i].second+=a[i-1].second;
    
    ll l=0, r=n, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (s+a[mid].second>=1000000) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<setprecision(8)<<a[ans].first;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}