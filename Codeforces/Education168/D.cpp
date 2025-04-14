//私はあなたがいなくて寂しいです
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()

using namespace std;
void debug_out() {cout << endl;}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

const int N = 2e5+5;
int n;
int a[N];
vector<int> E[N];
int ans;

void dfs(int u, int p) {
    int res = LLONG_MAX;
    for(int v: E[u]) {
        if(v==p) continue;
        dfs(v, u);
        res = min(res, a[v]);
    }
    if(u == 1) {
        ans = a[u] + res;
        return;
    }
    if(res == LLONG_MAX) return;
    if(res < a[u]) a[u] = res;
    else {
        a[u] += (res-a[u])/2;
    }
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) E[i].clear();

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=2; i<=n; i++) {
        int x; cin >> x;
        E[x].push_back(i);
        E[i].push_back(x);
    }
    dfs(1, 0);
    cout<< ans <<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int T=1;
    cin >> T;
    while(T--) {
        solve();
    }
}