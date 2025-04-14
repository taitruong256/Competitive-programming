#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;
    ll a[n+1], maxx=0;
    map<ll, ll> m;
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        ++m[a[i]];
        if (m[a[i]]>maxx) maxx=m[a[i]];
    }
    cout<<n-maxx;
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
