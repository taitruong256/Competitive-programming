#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

string bin(ll n)
{
    string ans;
    for (ll i=0; i<8; i++) if (n&(1LL<<i)) ans.push_back('1'); else ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    for (ll i=1; i<=200; i++) cout<<bin(10*i)<<" "<<10*i<<" "<<endl;
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