/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define endl '\n'
const ll mod = 1e9+7;
// vector<pair<ll, ll>> adj2[80005];
// vector<ll> adj[80005];
const int N = 1e5+5;
const int D = 19;
const int S = (1 << D);
int n, q, v[N];
vector<int> adj[N];
vector<pair<int,int>> E[N];
int sz[N], p[N], dep[N];
int st[S], id[N], tp[N], val[N];

void update(int idx, int val) {
	st[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) st[idx] = st[2 * idx] + st[2 * idx + 1];
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra += (ra, st[lo++]);
		if (hi & 1) rb += (rb, st[--hi]);
	}
	return ra+ rb;
}

void dfs(int u, int p) {

    for(auto[v, w]: E[u]) {
        if(v==p) continue;
        val[v] =w;
        dfs(v, u);
    }
}

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	p[cur] = par;
	for (int chi : adj[cur]) {
		if (chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}

int ct = 1;

void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
    // cout<<val[cur]<< " "<<id[cur]<<" "<<cur<<endl;
	update(id[cur], val[cur]);
	int h_chi = -1, h_sz = -1;
	for (int chi : adj[cur]) {
		if (chi == par) continue;
		if (sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if (h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for (int chi : adj[cur]) {
		if (chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}
int opt(int a, int b) {
    return a+b;
}
int path(int x, int y) {
	int ret = 0;
	while (tp[x] != tp[y]) {
        // cout<<tp[x]<<" "<<tp[y]<<endl;
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
		ret = opt(ret, query(id[tp[x]], id[x]));
		x = p[tp[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = opt(ret, query(id[x], id[y]));
	return ret;
}
void solve()
{
    // int n;
    cin >> n;
    for(int i=1; i<n;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs_sz(1, 0);
    dfs_hld(1, 0, 1);
    vector<int> ans(n+5, LLONG_MAX);
    ans[1] = 0;
    // cout<<path(3, 2)<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans[j] = min(ans[j], ans[i] + path(i,j));
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    // for (ll i=1; i<=n; i++) cout<<val[i]<<" "; cout<<endl;
    // cout<<query_path(1, 4)<<endl;
    // cout<<path(1, 2)<<endl;
    // cout<<query_path(2, 4)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}