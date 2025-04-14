#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;
const int maxn = 100005;
int a[maxn];
set<int>s[maxn];
set<int>::iterator k;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[a[i]].insert(i);
	}
	sort(a + 1, a + 1 + n);
	ll ans = n, mid = 1, t=n;
	for (int i = 1; i <= n; i++)
	{
		k = s[a[i]].lower_bound(mid);
		if (k == s[a[i]].end())
		{
			ans += t;
			mid = 1;
			k = s[a[i]].lower_bound(mid);
		}
		mid = *k;
		s[a[i]].erase(k);
		t--;
        cout<<ans<<endl;
	}
	cout << ans << endl;
}