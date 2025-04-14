#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[200005];

bool check(ll l, ll r)
{
    map<ll, ll> cnt;
    if (a[l]==a[r]) return false;
    for (ll k=l+1; k<r; k++)
        if (a[k]==a[l] || a[k]==a[r]) return false;
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll ans=0;
    for (ll r=1; r<=n; r++)
    {
        ll cnt=0;
        for (ll l=1; l<r; l++)
            if (check(l, r)==true) ++ans, ++cnt;
        cout<<cnt<<endl;
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
