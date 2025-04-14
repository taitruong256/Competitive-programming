#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 998244353;
void solve()
{
    //  p=a*Y
    //  q=b*Y
    //  X=p*q/__gcd(p, q)=p*q/Y=a*b*Y
    //  ==> dem so uoc cua X/Y 


    map<ll, ll> X, Y, sub;
    ll n; cin>>n;
    vector<ll> x(n);
    for (ll i=0; i<n; i++) cin>>x[i];
    for (ll i=0; i<n; i++) cin>>X[x[i]];
    ll m; cin>>m;
    vector<ll> y(m);
    for (ll i=0; i<m; i++) cin>>y[i];
    for (ll i=0; i<m; i++) cin>>Y[y[i]];

    for (auto [u, v]: Y) if (X.find(u)==X.end() || X[u]<v)
    {
        cout<<0;
        return;
    }

    for (auto [u, v]: Y) X[u]-=v;
    ll ans=1;
    for (auto [u, v]: X) ans=(ans*min(2LL, v+1))%mod;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}