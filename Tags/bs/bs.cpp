#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bs(ll *a, ll n, ll x)
{
    ll l=0, r=n-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (a[mid]==x) return mid;
        else if (a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

void solve()
{
    ll n, x; cin>>n>>x;
    ll a[n+1];
    for (ll i=0; i<n; i++) cin>>a[i];
    cout<<bs(a, n, x);
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
