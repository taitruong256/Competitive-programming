#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    ll sum=0, a[n+5],c=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    
    for (ll i=1; i<=n; i++) {
        if((1.0/a[i])>=1.0/(4*m)) c++;
    }

    
    if (c>=m) cout<<"Yes";
    else cout<<"No";
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