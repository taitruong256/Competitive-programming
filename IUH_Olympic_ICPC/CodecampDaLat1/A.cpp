#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;


int dis(int x, int y) {
    return abs(x)+ abs(y);
}

void solve() {
    int ans = 0;
    int n, k; cin >> n >> k;
    string a; cin >> a;
    int x = 0, y = 0, L = 0, U = 0;

    for(int i=0; i<n; i++) {
        if(a[i]=='L') {
            // x--;
            L++;
        }
        else if(a[i]=='R') {
            // x++;
            L--;
        }
        else if(a[i]=='U') {
            // y++;
            U++;
        }
        else {
            // y--;
            U--;
        }
      
    }
    x += L*(k-1);
    y += U*(k-1);
    // cout<<x<<" "<<y<<endl;
    ans = max(ans, dis(x, y));
    // cout<<ans<<'\n';
    // L = 0, U = 0;
    for(int i=0; i<n; i++) {
        if(a[i]=='L') {
            x--;
            L++;
        }
        else if(a[i]=='R') {
            x++;
            L--;
        }
        else if(a[i]=='U') {
            y++;
            U++;
        }
        else {
            y--;
            U--;
        }
        ans = max(ans, dis(x, y));
    }
    cout<<ans<<'\n';
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T; cin >> T;
    while(T--)
    solve();
    return 0;
}