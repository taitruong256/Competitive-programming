#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin>>n;
	vector<ll> ans;
	for (ll i=1; i<=n; i++) if (n%i==0) 
	{
		ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(ll i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
	return 0;
}
