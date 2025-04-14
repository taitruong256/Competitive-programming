#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int maxn = 1e5 + 5, LOG = 17;
int par[LOG + 1][maxn], high[maxn];
vector<int> e[maxn];

void dfs(int u = 1, int p = 0) {
    for(int v : e[u]) if(v != p) {
        par[0][v] = u;
        high[v] = high[u] + 1;
        for(int i = 1; i <= LOG; i++) par[i][v] = par[i - 1][par[i - 1][v]];
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(high[u] < high[v]) swap(u, v);
    for(int i = LOG; i >= 0; i--) if(high[par[i][u]] >= high[v]) u = par[i][u];
    if(u == v) return u;
    for(int i = LOG; i >= 0; i--) if(par[i][u] != par[i][v]) {
        u = par[i][u];
        v = par[i][v];
    }
    return par[0][u];
}

void Solve() {
    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    high[0] = -1;
    dfs();

    while(q--) {
        int x, y, z; cin >> x >> y >> z;
        int xy = lca(x, y), xz = lca(x, z), yz = lca(y, z);

        if((xy ^ xz ^ yz) == y) cout << "YES\n";
        else cout << "NO\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
    int t = 1;// cin >> t;
    while(t--) Solve();
}