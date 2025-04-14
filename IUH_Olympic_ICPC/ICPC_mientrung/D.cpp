#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 105, MOD = 2023;
const int maxn = 1e5+5;
int mp[maxn];
vector<int> adj[N];
int a[N];
ll dp[N][N][N];
int n;

inline void dfs(int st, int u, int cnt) {
    dp[st][u][cnt]++;
    for(int v: adj[u])  {
        dfs(st, v, cnt+1);
    }
}




void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++) {
        mp[a[i]] = i;
    }
    for(int i = 1; i<=n; i++) {
        for(int j = i+1; j<=n; j++) {
            if(gcd(a[i], a[j])==1) adj[i].push_back(j);
        }
    }
    for(int i=1; i<=n; i++) {
        dfs(i, i, 0);
    }
    int q;
    cin >> q;
    
    while(q--) {
        int u, v, k; cin >> u >> v >>k;
        u = mp[u];
        v = mp[v];
        cout<<dp[u][v][k]%MOD<<'\n';
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