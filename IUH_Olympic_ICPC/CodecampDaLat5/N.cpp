#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 9, MOD = 1e9 + 7;
vector<vector<int>> arr = {{1,1}, {1,0}};
vector<vector<int>> nhanmt(vector<vector<int>> a, vector<vector<int>> b, int mod) {
    vector<vector<int>> res(2, vector<int>(2));
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    return res;
}
vector<vector<int>> pwmt(vector<vector<int>> a, int x, int mod) {
    if (x == 1) {
        return a;
    }
    vector<vector<int>> tmp = pwmt(a, x/2, mod);
    tmp = nhanmt(tmp, tmp, mod);
    if (x&1) tmp = nhanmt(tmp, arr, mod);
    return tmp;
}
void solve() {
    int n, m, bandau;
    cin >> n;
    vector<vector<int>> mt1(2, vector<int>(2));
    auto mt2 = mt1;
    if (n == 2) cout << 3 << endl;
    else if (n == 5) cout << 20;
    else {
        bandau = n;
        if (n % 5 == 4 || n % 5 == 1) {
            n--;
        }
        else {
            n = 2 * n + 2;
        }
        vector<int> uoc;
        // cout << "n " << n << endl;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                uoc.push_back(i);
                uoc.push_back(n/i);
            }
        }
        m = sqrt(n);
        if (n % m == 0) {
            uoc.push_back(m);
        }
        sort(uoc.begin(), uoc.end());
        // for (auto x: uoc) cout << x << endl;
        bool ok;
        for (int i = 0; i < uoc.size(); i++) {
            ok = 1;
            for (int j = 1; j <= 5; j++) {
                mt1 = pwmt(arr, j, bandau);
                mt2 = pwmt(arr, j + uoc[i], bandau);
                if (mt1[0][0] != mt2[0][0]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << uoc[i] << endl;
                return;
            }
        }
        assert(1 > 2);
    }
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    // cout << "HellO";
    return 0;
}