#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

bool comp(string a, string b)
{
    while (a.size()<10) a.push_back('9');
    while (b.size()<10) b.push_back('9');
    return a>b;
}

void solve()
{
    ll n; cin>>n;
    string s[n+5];
    for (ll i=1; i<=n; i++) cin>>s[i];
    sort(s+1, s+n+1, comp);
    for (ll i=1; i<=n; i++) cout<<s[i];
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