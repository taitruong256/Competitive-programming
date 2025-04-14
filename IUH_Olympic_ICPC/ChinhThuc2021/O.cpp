#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct toado
{
    ll x, y;
};

bool sosanh1(toado a, toado b)
{
    return a.x<b.x;
}

bool sosanh2(toado a, toado b)
{
    return a.y<b.y;
}

void solve()
{
    ll n; cin>>n;
    toado a[n+1], b[n+1];
    for (ll i=1; i<=n; i++) cin>>a[i].x>>a[i].y;
    for (ll i=1; i<=n; i++) b[i]=a[i];
    sort(a+1, a+n+1, sosanh1);
    sort(a+1, a+n+1, sosanh2);
    for (ll i=1; i<=n; i++) cout<<a[i].x<<" ";
    
    ll ans=0, d=0;
    for (ll i=2; i<=n; i++) 
        if (a[i].x==a[i-1].x) ++d;
        else
        {
            ans=ans+d*(d+1)/2;
            d=0;
        }
    
    d=0;
    for (ll i=2; i<=n; i++) 
        if (a[i].y==a[i-1].y) ++d;
        else
        {
            ans=ans+d*(d+1)/2;
            d=0;
        }
    cout<<ans;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
