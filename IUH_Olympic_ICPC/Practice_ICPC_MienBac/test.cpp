/* ---While (I <= you) I++;---*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define cint int t; cin >> t; while(t--)
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define what_is(x) cerr << #x << " is " << x << endl;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
string s, t = "ICPC";
// int sparse[100000][100000];

// void dequy(int n)
// {
//     vector<int> v(1000000);
//     dequy(n-1);
// }

void solve() {
    // vector<int> v(10);
    // cout<<v[1e9];
    s = '#' + s;
    vector<vector<int>> dp(4, vector<int>(s.size()));
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'I') {
            dp[0][i]++;
        }
        dp[0][i] += dp[0][i-1];
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == t[i]) {
                if (j-2 >= 0)
                    dp[i][j] += dp[i-1][j-2];
            }
            dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[3][s.size()-1] << endl;
    
}
signed main () {
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ios
    cin >> s;
    do {
        solve();
        cin >> s;
    } while(s != "$");
    return 0;
}
