/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
ll pref[100005], a[100005], suff[100005], b[100005];

bool check(ll x)
{
    ll remains = 0;
    for (ll i = 1; i <= n; ++i)
    {
        ll water = b[i] - a[i];
        ll drain = max(0LL, min(x, b[i]) - a[i]);
        remains += water - drain;
        if (remains >= m) return true;
    }

    return false;
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>a[i];
    pref[0]=0;
    suff[n+1]=0;
    for (ll i=1; i<=n; i++) pref[i]=max(pref[i-1], a[i]);
    for (ll i=n; i>=1; i--) suff[i]=max(suff[i+1], a[i]);
    for (ll i=1; i<=n; i++) b[i]=min(pref[i], suff[i]);

    ll l=*min_element(a+1, a+n+1), r=*max_element(a+1, a+n+1), ans=0, mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
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