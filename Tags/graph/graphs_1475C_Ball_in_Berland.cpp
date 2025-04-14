/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    ll a[n+5], b[m+5];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    vector<pair<ll, ll>> edge(k);
    for (ll i=0; i<k; i++) cin>>edge[i].first, ++a[edge[i].first];
    for (ll i=0; i<k; i++) cin>>edge[i].second, ++b[edge[i].second];
    ll ans=0;
    for (ll i=0; i<k; i++) ans+=k-a[edge[i].first]-b[edge[i].second]+1;
    cout<<ans/2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}