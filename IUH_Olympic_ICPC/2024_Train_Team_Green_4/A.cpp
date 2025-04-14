#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll dp[1005];

void solve()
{
    ll n, a, b, d; cin>>n>>a>>b>>d;
    ll ans1=n*a;
    ll ans2=n/d*b+(n-n/d*d)*a;
    ll ans3=(n+d-1)/d*b+((n+d-1)/d*d-n)*a;
    cout<<min({ans1, ans2, ans3});
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}