#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

ll nC2(ll n)
{
    return n*(n-1)/2;
}

ll nC3(ll n)
{
    return n*(n-1)*(n-2)/6;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) ++cnt[a[i]];




    __int128_t ans=0;
    vector<pair<ll, ll>> val;
    for (auto [x, y]: cnt) val.push_back({x, y});
    for (auto [x, y]: val) ans+=nC3(y);         
    for (auto [x, y]: val) 
    {
        ans+=(__int128_t)(y)*nC2(cnt[x-1]);
        ans+=(__int128_t)(cnt[x-1])*nC2(y);               
    }                                      
    for (auto [x, y]: val) 
    {
        ll a=cnt[x-1];
        ll b=cnt[x];
        ll c=cnt[x+1];
        ans+=a*b*c;
    }





    if (ans==0)
    {
        cout<<0;
        return;
    }
    string s;
    while (ans>0)
    {
        s.push_back(char('0'+ans%10));
        ans/=10;
    }
    reverse(s.begin(), s.end());
    cout<<s;
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