#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int a[n+5];
    for(int i=0; i<n; i++) cin >> a[i];
    map<int,int> mp;
    for(int mask = 1; mask<(1<<n); mask++) {
        int res = 0;
        for(int i = 0; i<n;i++) {
            if(mask&(1<<i)) res= gcd(res, a[i]);
        }
        mp[res]++;
        ans+=res;
    }
    for(auto p: mp) cout<< p.first<<" "<<p.second<<'\n';
    cout<<ans;
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
    solve();
    return 0;
}