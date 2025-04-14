#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool chinhphuong(ll n)
{
    ll t=sqrt(n);
    if (t*t==n) return true; 
    else return false;
}

void solve()
{
    ll n; cin>>n;
    ll ans=1;
    for (ll i=2; i<=sqrt(n); i++) 
    {
        if (i*i<=n) ++ans;
        if (i*i*i<=n && chinhphuong(i*i*i)==false) ++ans;
    }
    cout<<ans<<endl;
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
