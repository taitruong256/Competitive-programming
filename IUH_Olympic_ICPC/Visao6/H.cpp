#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll cnt[2000005], a[200005];

void solve()
{

    ll n; cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j*j<=a[i]; j++) if (a[i]%j==0) 
        {
            ++cnt[j];
            if (a[i]/j!=j) ++cnt[a[i]/j];
        }
    }
    long long ans=0;
    for (ll i=1; i<=2000000; i++) if (cnt[i]>=2) ans=max(ans, (long long)i*cnt[i]);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}