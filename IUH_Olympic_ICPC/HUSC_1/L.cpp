#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n;
string s[2005];
vector<string> _left, _right;

ll to_mask(string s, string t)
{
    ll ans=0;
    for (ll i=0; i<4; i++) 
        if (s[i]==t[i])
            ans+=(1LL<<i);
    return ans;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>s[i];

    ll ans=0;
    for (ll j=2; j<=n-1; j++)
    {
        _left.clear();
        _right.clear();
        for (ll mask=0; mask<(1LL<<4); mask++)
        {
            for (ll i=1; i<=j-1; i++) 
                if (to_mask(s[i], s[j])==mask) _left.push_back(s[i]);
            for (ll k=j+1; k<=n; k++)
                if (to_mask(s[j], s[k])==mask) _right.push_back(s[k]);
            for (string x: _left)
                for (string y: _right)    
                    if (to_mask(x, y)==mask) 
                        ++ans;
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