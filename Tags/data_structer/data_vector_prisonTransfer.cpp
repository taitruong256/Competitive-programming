#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, t, c; cin>>n>>t>>c;
    vector<ll> a(n);
    for (auto& x:a) cin>>x;
    ll d=0, ans=0;
    for (ll i=0; i<n; i++) 
        if (a[i]<=t) ++d;
        else
        {
            ans+=max(0LL, d-c+1);
            d=0;
        }
    ans+=max(0LL, d-c+1);
    cout<<ans;
}

int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
