#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7;

const int N = 5e3;
int n;
int dp[N+5], one[N+5];

int binpow(int a, int b) {
    int res = 1;
    while(b>0) {
        if(b&1) res = (res*a)%MOD;
        b>>=1;
        a*=a;
        a%=MOD;
    }
    return res;
}

void solve() {
    cin >> n;
    int a[n+5];
    for(int i=1; i<=n; i++) { 
        cin >> a[i];
        one[a[i]]++;
    }
   dp[0] =1;
    for(int i=1; i<=n; i++) {
        for(int j=N; j>=a[i]; j--) {
            dp[j]+=dp[j-a[i]];
            dp[j]%=MOD;
        }
    }
    int base = binpow(2, n);
    base = (base-n+MOD)%MOD;
    int c2n = ((n*(n-1))%MOD*binpow(2, MOD-2))%MOD;
    base = (base-c2n-1+MOD)%MOD;
    // cout<< base<<endl;
    // for(int i=1; i<=5; i++) cout<< dp[i]<<'\n';
    // for(int i=1; i<)
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=a[i]; j++) {
            // base=(base-(dp[j]-one[j]+MOD)+MOD)%MOD;
            base = (base- dp[j]+MOD)%MOD;
            base = (base+ one[j]+MOD)%MOD;
        }
    }
    cout<<base<<'\n';
}
signed main () {
    ios
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    solve();
    return 0;
}