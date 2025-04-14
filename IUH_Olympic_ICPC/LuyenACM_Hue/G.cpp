#include <bits/stdc++.h>
#define taskname "G"
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int n;
ii A[1010];
ll ans;

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y;
	A[n+1] = A[1];
}
void Solve(){
	for (int i = 2; i <= n+1; i++)
		ans += (A[i].x - A[i-1].x) * (A[i].y + A[i-1].y);
	cout << abs(ans);
}

int main(){
	Input();
	Solve();
	return 0;
}