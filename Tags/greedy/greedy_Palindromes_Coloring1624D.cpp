/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    map<char, ll> cnt;
    for (auto c: s) ++cnt[c];
    ll cntPair=0, cntOdd=0;
    for (auto it: cnt)
    {
        cntPair+=it.second/2;
        cntOdd+=it.second%2;
    }
    ll ans=2*(cntPair/k);
    cntOdd+=2*(cntPair%k);
    if (cntOdd>=k) ++ans;
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}