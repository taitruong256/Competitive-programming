#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, y, z; cin>>n; 
    ll x[n+1], d[n+1];
    for (ll i=1; i<=n; i++) cin>>x[i];
    cin>>y>>z;   
    for (int i=1; i<=n; i++) d[i]=abs(x[i]-z);
    sort(d+1, d+n+1); //  for(int i=1;i<=n; i++) cout<<d[i]<<" "; cout<<endl;
    ll ans=0, s=0;
    y=abs(y-z);
    while (s<y)
    {
        ++ans;
        s=s+d[ans];
    }
    if (ans==0) cout<<0; else cout<<ans-1;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
