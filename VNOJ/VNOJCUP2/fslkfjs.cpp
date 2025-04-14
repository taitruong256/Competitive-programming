#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define debug(a) cout << #a << " = " << a << '\n'
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define vll vector<vector<ll>>
#define ld long double
#define ll long long
#define db double
#define INF 1e18
#define S second
#define F first
using namespace std;
using namespace __gnu_pbds;
typedef pair<long long, long long> node;
typedef tree<node, null_type, less<node>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
ll n,m,k;  
vector<vector<ll>> a; 

map<pair<ll,ll>,ll> mm; 

ll dp( ll n, ll k )
{

    if( k == 0 || n == 0 ) return 0; 
    if( mm[{n,k}] ) return mm[{n,k}]; 
    ll res = -INF; 
    for( int i = k-min(k,m); i <= min(k,m*(n-1)); i++ )
    { 
        ll c; 
        if(mm[{n-1,i}]) c =  mm[{n-1,i}]; 
        else c = dp(n-1, i ); 
        res = max(res, c + a[n][min(k-i,m)] ); 

    }
    mm[{n,k}]=res;  

    return res; 
}
int solve()
{
    cin >> n >> m >> k; 
    a.assign(n+1, vector<ll>(m+1)); 
    for(int i = 1; i <= n; i++ )
    {
        for(int j = 1; j <= m; j++ )
        {
            ll x; cin >> x; 
            a[i][j] = a[i][j-1] + x; 
        }
    }
    cout << dp(n,k); 
    return 0;
}
main()
{
ios::sync_with_stdio(false);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // long long t;
    // cin >> t;
    // while (t--)
        solve();
}