/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>> canh[1005];
ll n, q, value=0;
bool dau[1005];

void dfs(ll p, ll u, ll t, ll val) {
	if (u == t) {
		value = val;
		return ;
	}
	for (auto k : canh[u]) {
		ll v = k.first, c = k.second;
		if (v == p) continue;
		dfs(u, v, t, val + c);
	}
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v, c; cin>>u>>v>>c;
        canh[u].push_back({v, c});
        canh[v].push_back({u, c});
    }

    for (ll i=1; i<=q; i++)
    {
        ll u, v; cin>>u>>v;     // cout<<"   --    "<<u<<" "<<v<<endl;
        value=0;
        memset(dau, false, sizeof(dau));
        dfs(0, u, v, 0);        //cout<<endl;
        cout<<value<<endl;
    }
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