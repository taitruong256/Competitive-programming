#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ucln(ll a, ll b)
{
    while (a%b!=0)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return b;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+1];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll le=a[1], chan=a[2];
    for (ll i=1; i<=n; i++) 
        if (i%2==0) chan=ucln(chan, a[i]);
        else le=ucln(le, a[i]);

    bool ok_le=true, ok_chan=true;
    for (ll i=1; i<=n; i++)
        if (i%2==0 && a[i]%le==0) ok_le=false;
        else if (i%2==1 && a[i]%chan==0) ok_chan=false;
    //printf("----le = %lld chan = %lld ----\n", le, chan);
    //printf("----ok_le = %d  ok_chan = %d ----\n", ok_le, ok_chan);
    if (ok_le==true) cout<<le<<"\n";
    else if (ok_chan==true) cout<<chan<<"\n";
    else cout<<0<<"\n";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
