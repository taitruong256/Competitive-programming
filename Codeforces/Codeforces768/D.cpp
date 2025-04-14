#include<bits/stdc++.h>

using namespace std;
using LL = long long;
#define debug(a) cout << #a <<": "<< a << '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(a) int(a.size())



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    clock_t start = clock();


    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        if (k == n - 1) {
            vector<pair<int, int>> ans;
            ans.pb({n - 2, n - 1});
            ans.pb({1, 3});
            bool ok = true;
            if (n - 2 == 3 || n - 1 == 3) ok = false;
            for (int i = 2, j = n - 3; i <= j; ++i, --j) {
                if (i == j) {
                    ok = false;
                }
                if (i == 3) ans.pb({0, j});
                else if (j == 3) ans.pb({i, 0});
                else ans.pb({i, j});
            }
            if (!ok) {
                cout << -1 << '\n';
                continue;
            }
            for (auto [k, v] : ans) cout << k << ' ' << v << '\n';
        } 
        else {
            vector<pair<int, int>> ans;
            ans.pb({k, n - 1});
            bool ok = true;
            for (int i = 1, j = n - 2; i <= j; ++i, --j) {
                if (i == j) {
                    ok = false;
                }
                if (i == k) ans.pb({0, j});
                else if (j == k) ans.pb({i, 0});
                else ans.pb({i, j});
            }
            if (!ok) {
                cout << -1 << '\n';
                continue;
            }
            for (auto [k, v] : ans) cout << k << ' ' << v << '\n';
        } 

    }

    


    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << double (end - start) / double (CLOCKS_PER_SEC) << '\n';
    return 0;
}