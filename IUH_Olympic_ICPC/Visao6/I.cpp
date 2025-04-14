#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll tongchuso(ll n)
{
    ll s=0;
    while (n>0) 
    {
        s+=n%10;
        n/=10;
    }
    return s;
}

bool check(ll n)
{
    ll cnt=__builtin_popcount(n);
    return cnt==1;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5], ans=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++)
    {
        for (ll j=0; j<=1000; j++) if (check(tongchuso(a[i]+j)))
        {
            ans+=j;
            break;
        }
    }
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