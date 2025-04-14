#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int maxn = 8e2 + 2;
int fw[maxn][maxn];
vector<pair<int, int>> e[maxn * maxn];

void upd(int idx, int idy, int val) {
    for(; idx < maxn; idx += idx & -idx) {
        for(int y = idy; y < maxn; y += y & -y) {
            fw[idx][y] += val;
        }
    }
}

int get(int idx, int idy) {
    int res = 0;
    for(; idx > 0; idx -= idx & -idx) {
        for(int y = idy; y > 0; y -= y & -y) {
            res += fw[idx][y];
        }
    }
    return res;
}

void Solve(int testcase) {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n * m; i++) e[i].clear();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x; cin >> x;
            e[x].push_back({i, j});
        }
    }

    auto query = [&] (int x1, int y1, int x2, int y2) {
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    };

    int lo = 1, hi = 800, ans;
    while(lo <= hi) {
        int mid = lo + hi >> 1;

        int val = 0; memset(fw, 0, sizeof(fw));
        for(int i = 1; i <= n * m; i++) {
            if(e[i].empty()) continue;

            for(auto& [x, y] : e[i]) {
                int x1 = max(1LL, x - mid), y1 = max(1LL, y - mid);
                int x2 = min(n, x + mid), y2 = min(m, y + mid);

                val += query(x1, y1, x2, y2) * 2; 
            }

            for(auto& [x, y] : e[i]) upd(x, y, 1);
        }

        if(val >= k) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    cout << "Case #" << testcase << ": ";
    cout << ans << el;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++) Solve(i);
}