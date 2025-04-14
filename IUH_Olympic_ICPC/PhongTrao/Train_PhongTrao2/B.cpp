#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n; cin>>n;
	ll a[n+5], b[n+5];
	for (ll i=0; i<n; i++) cin>>a[i];
	for (ll i=0; i<n; i++) cin>>b[i];
	sort(a, a+n);
	sort(b, b+n);
	for (ll i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
	for (ll i=0; i<n; i++) cout<<b[i]<<" ";
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t; cin>>t;
	while (t--) solve();
	return 0;
}
