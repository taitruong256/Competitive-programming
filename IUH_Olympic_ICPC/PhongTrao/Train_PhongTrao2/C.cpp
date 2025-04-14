#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n; cin>>n;
	string s; cin>>s;
	if (s.size()==1)
	{
		cout<<"Yes";
		return;
	}
	map<char, ll> cnt;
	for (ll i=0; i<s.size(); i++) ++cnt[s[i]];
	bool ok=false;
	for (ll i=0; i<s.size(); i++) if (cnt[s[i]]>1)
	{
		cout<<"Yes";
		ok=true;
		return;
	}
	if (ok==false) cout<<"No";
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
