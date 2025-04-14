#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll w, h; cin>>w>>h;
    ll ngang=0, doc=0;
    for (ll i=0; i<2; i++)
    {
        ll k; cin>>k;
        ll tmax=0, tmin=10000005;
        for (ll j=0; j<k; j++)
        {
            ll x; cin>>x;
            tmax=max(tmax, x);
            tmin=min(tmin, x);
        }
        ngang=max(ngang, tmax-tmin);
    }

    for (ll i=0; i<2; i++)
    {
        ll k; cin>>k;
        ll tmax=0, tmin=10000005;
        for (ll j=0; j<k; j++)
        {
            ll x; cin>>x;
            tmax=max(tmax, x);
            tmin=min(tmin, x);
        }
        doc=max(doc, tmax-tmin);
    }

    cout<<max(ngang*h, doc*w)<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
