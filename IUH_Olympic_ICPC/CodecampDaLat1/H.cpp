#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e2 + 9, MOD = 1e9 + 7;


vector<int> adj[N], adj2[N];

int color[N];
bool used[N];
int cnt=0;
bool cycle = false;

void check(int u) {
    color[u] = 1;
    for(int v: adj[u]) {
        if(!color[v]) check(v);
        else if(color[v]==1) {
            cycle = true;
            return;
        }
    }
    color[u] = 2;
}

void dfs(int u)
{
    used[u]=true;
    ++cnt;
    for (auto v: adj[u]) if (used[v]==false) dfs(v);
}

void dfs2(int u)
{
    used[u]=true;
    ++cnt;
    for (auto v: adj2[u]) if (used[v]==false) dfs2(v);
}

void init()
{
    cycle=false;
    for (int i=1; i<=100; i++) used[i]=false;
    for (int i=1; i<=100; i++) color[i]=0;
    cnt=0;
    for (int i=1; i<=100; i++) adj[i].clear(), adj2[i].clear();
}

int child[N], parent[N];

void solve() {
    init();
    int n, m; cin >> n >> m;
    
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++) {
        if(!color[i])
            check(i);
    }
    if(cycle) {
        for(int i=1; i<=n; i++) cout<<0;
        cout<<'\n';
        return;
    }

    for(int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) used[j]=false;
        cnt=0;
        dfs(i);
        child[i]=cnt;
    }

    for(int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) used[j]=false;
        cnt=0;
        dfs2(i);
        parent[i]=cnt;
    }   


    for (int i=1; i<=n; i++) if (child[i]<=(n+1)/2 && parent[i]<=(n+1)/2) cout<<1; else cout<<0;
    cout<<endl;

}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
    solve();
    return 0;
}