#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> isprime(1000005, true);

void khoitao()
{
	isprime[1]=false;
	
	for(ll i=2;i<=1000005;i++) if(isprime[i]==true)
		for(ll j=2*i;j<=1000005;j+=i) isprime[j]=false;
	//for (ll i=1; i<=1000; i++) if (isprime[i]==true) cout<<i<<" ";
}

void solve()
{
    ll n, e;
	cin>>n>>e;
	ll a[n+1], ans=0;
	for (ll i=1; i<=n; i++) cin>>a[i];
	
	//day n thoa khi 1 so nt n-1 so 1
	for (int i = n; i >= n - e + 1; --i) 
    {
		int cnt = 0, prev = 0;
		bool fl = 0;
		for (int j = i; j > 0; j -= e) 
        {
			if (a[j] == 1) ++cnt;
			else if (isprime[a[j]]) 
            {
				prev = cnt;
				fl = 1;
				cnt = 0;
			}
			else cnt = prev = fl = 0;
			if (fl) ans += prev + 1 - isprime[a[j]];
		}
	}

	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    khoitao();
    ll t; cin>>t;
    while (t--) solve();
	return 0;
}