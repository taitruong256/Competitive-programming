#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9+7;
ll a[1000005], b[1000005];

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>b[i];
    Tree<pair<ll, ll>> toanbo, truoc;
    vector<ll> sau;
    for (ll i=1; i<=n; i++) toanbo.insert({a[i], i});
    for (ll i=1; i<=n; i++) 
    {
        if (truoc.empty()) truoc.insert({a[i], i});
        else if (a[i]>=(*truoc.rbegin()).first) truoc.insert({a[i], i});
        else 
        {
            for (ll j=i+1; j<=n; j++) sau.push_back(a[j]);
            break;
        }
    }

    sort(b+1, b+m+1);
    for (ll i=1; i<=m; i++)
    {
        ll k=toanbo.order_of_key({a[i], i+n})-truoc.order_of_key({a[i], i+n}); //be hon o sau
        ll l=toanbo.order_of_key({a[i], i+n});  //lon hon toan bo mang
        if (k>=l) truoc.insert({a[i], i+n});
        else sau.push_back(a[i]);
    }


    for (auto i: truoc) cout<<i.first<<" "; 
    for (auto i: sau) cout<<i<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}