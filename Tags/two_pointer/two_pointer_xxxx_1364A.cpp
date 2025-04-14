#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, x, count=0, s=0; cin>>n>>x;
    ll a[n+1];
    for (ll i=0; i<n; i++) 
    {
        cin>>a[i];
        s+=a[i];
        if (a[i]%x==0) ++count;
    }      

    if (count==n) {cout<<-1<<"\n"; return;}
    if (s%x!=0){ cout<<n<<"\n"; return;}
    ll l=0, r=n-1;
    while (s%x==0)
    {
        if (a[l]%x!=0) s-=a[l];
        else if (a[r]%x!=0) s-=a[r];
        ++l; --r;
    }
    cout<<max(r+1, n-l)<<"\n";
}

int main() {                   
    FAST;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin>>t; 
    while (t--) solve();
    return 0;
}
