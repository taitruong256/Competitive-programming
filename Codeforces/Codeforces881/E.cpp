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
void solve() {
	int n, m, x;
	cin >> m >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	int q;
	cin >> q;
	vector<int> b(q+1);
	for (int i = 1; i <= q; i++) {
		cin >> b[i];
	}
	int ans = -1, l = 1, r = q, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		vector<int> tmp(m + 1);
		for (int i = 1; i <= mid; i++) {
			tmp[b[i]] = 1;
		}
		for (int i = 1; i <= m; i++) tmp[i] += tmp[i-1];
		bool kt = false;
		for (auto [ff, ss]: a) {
			int sl1 = tmp[ss] - tmp[ff-1];
			if (sl1 > (ss - ff + 1 - sl1)) {
				kt = true;
				break;
			}
		}
		if (kt) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
 	}
	cout << ans << endl;
}
signed main () {
	#ifndef ONLINE_JUDGE
	freopen("_input.txt", "r", stdin);
	freopen("_output.txt", "w", stdout);
	#endif
	ios 
    int tt;
    cin >> tt;
    while (tt--)
	solve();
	return 0;
}