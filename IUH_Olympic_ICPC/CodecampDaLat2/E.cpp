#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;

int f(int x) {
    return x*(x+1)/2;
}

void solve() {
    int n, k, e;

    cin >> n >> k >> e;
    int a = e, b = n-e-k;
    int lim = max(a, b);
    if(lim>k) {
        // cout<<"*";
        int target = min(a, b);
        vector<int> dp(target+5);
        dp[0] = 1;
        for(int i=1; i<lim; i++) {
            if(i==k) continue;
            for(int j = target; j>=i; j--) {
                dp[j] |=dp[j-i];
            }
        }
        for(int i=target; i>=0; i--) {
            if(dp[i]) {
                cout<<target-i<<'\n';
                return;
            }
        }
    }
    else if(k>lim) {
        cout<<a+b-min(a+b, f(lim))<<'\n';
    }
    else {
        int ans = a+b- min(f(k-1), a+b);
        // cout<<min(f(k-1),a+b)<<endl;
        cout<<ans<<'\n';
    }
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}