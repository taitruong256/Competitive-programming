#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    map<ll, ll> cnt;
    ll l=1, ans=1, distinct=0;
    a[0]=a[1];
    for (ll r=1; r<=n; r++)
    {
        cnt[a[r]]++;
        if (cnt[a[r]]==1) ++distinct;
        while (distinct>k) 
        {
            --cnt[a[l]];
            if (cnt[a[l]]==0) --distinct;
            ++l;
        } 
        if (a[r]-a[r-1]>1) 
        {
            l=r;
            cnt.clear();
            cnt[r]=1;
            distinct=1;
        };
        ans=max(ans, r-l+1);
    }
    cout<<ans;
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