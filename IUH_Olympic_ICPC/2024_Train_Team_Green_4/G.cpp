#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    multiset<ll> ms;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        ms.insert(x);
    }
    while (ms.size()>1)
    {
        ll x=*ms.begin();
        ll y=*ms.rbegin();
        ms.erase(ms.find(x));
        ms.erase(ms.find(y));
        ms.insert((x+y)/2);
    }
    cout<<*ms.begin();
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