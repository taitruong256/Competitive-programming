//私はあなたがいなくて寂しいです
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define double long double
using namespace std;
void debug_out() {cout << endl;}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
   cout << H << ' ';
   debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
pair<ll, ll> queries[1000005];
ll pre=1, res[1000005];

void solve(ll tc) {
    int n=queries[tc].first;
    int l=n*3, r= n*5;
	int ans;
	while(l<=r) {
		int mid = l + r >> 1;
		int tmp = mid;
		int cnt = 0;
		while(tmp>0) {
			cnt += tmp/5;
			tmp/=5;
		}
		if(cnt >= n) {
			ans = mid;
			r = mid -1;
		}
		else l = mid + 1;
	}
	pre=n;
	res[queries[tc].second]=ans;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	ll T; cin>>T;
    for (int i=1; i<=T; i++)
        cin>>queries[i].first, queries[i].second=i;

	sort(queries+1, queries+T+1);
	for (ll i=1; i<=T; i++)
		solve(i);
	for (ll i=1; i<=T; i++)
		cout<<res[i]<<'\n';
}
//1906