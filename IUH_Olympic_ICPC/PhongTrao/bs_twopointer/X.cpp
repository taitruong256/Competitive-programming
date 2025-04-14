/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, d; cin>>n>>d;
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    a[n+1].first=1e9; a[n+1].second=1e9;
    sort(a+1, a+n+1);
    ll sum[n+5];
    sum[0]=0;
    for (ll i=1; i<=n; i++) sum[i]=sum[i-1]+a[i].second;
    // for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
    // for (ll i=1; i<=n; i++) cout<<sum[i]<<" "; cout<<endl;

    ll res=0;
    for (ll i=1; i<=n; i++)
    {
        ll l=1, r=n+1, ans=n+1;
        while (l<=r)
        {
            ll mid=(l+r)/2;
            if (a[mid].first>=a[i].first+d) ans=mid, r=mid-1;
            else l=mid+1;
        }
        // cout<<i<<" "<<ans<<endl;
        res=max(res, sum[ans-1]-sum[i-1]);
    }
    cout<<res;
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