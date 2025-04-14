/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

void solve()
{
    unordered_set v[3];
	long long n,a,i,ans,k,l;
	string s;
	cin >> n;
	cin >> s;
	a=0;
	ans=0;
	v[0].insert({0,0});
	for(i=1;i<=n;i++){
		if(s[i-1]=='+'){
			a=a+1;
		}
		k=(a+i)%3;
		l=v[k].order_of_key({i-2*a,i})*1ll;
		ans=ans+l;
		v[k].insert({i-2*a,i});
	}
	cout << ans << "\n";
	return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}