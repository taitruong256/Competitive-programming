#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    map<ll, ll> cnt;
    ll l=1, ans=0;
    for (ll r=1; r<=n; r++)
    {
        ++cnt[a[r]];
        if (cnt[a[r]]==2)
            while (cnt[a[r]]==2) --cnt[a[l++]];
        ans+=(r-l);
        cout<<r-l<<endl;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
