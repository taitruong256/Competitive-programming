#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, char> a, pair<ll, char> b)
{
	return a.first>b.first;
}

void solve()
{
	string s; cin>>s;
	ll k; cin>>k;
	vector<pair<ll, char>> v;
	ll val[300];
	for (ll i=0; i<26; i++)
	{
		ll value; cin>>value;
		val['a'+i]=value;
		v.push_back({value, 'a'+i}); 
	}

	sort(v.begin(), v.end(), cmp);
	//for (auto it: v) cout<<it.first<<" "<<it.second<<endl;
	for (ll i=0; i<k; i++) s=s+char(v[0].second);
	//cout<<s<<endl;
	ll ans=0;
	for (ll i=0; i<s.size(); i++) 
	{       
		ans+=(i+1)*val[s[i]];
		//cout<<ans<<endl;
	}
	cout<<ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
	solve();
	return 0;
}
