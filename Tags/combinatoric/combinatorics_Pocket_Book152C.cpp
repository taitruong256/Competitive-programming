/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;

void solve()
{
    ll n, m; cin>>n>>m;
    string s[n+5];
    for (ll i=0; i<n; i++) cin>>s[i];
    set<char> st[m+5];
    for (ll i=0; i<n; i++)
        for (ll j=0; j<m; j++) st[j].insert(s[i][j]);
    
    ll ans=1;
    for (ll i=0; i<m; i++) ans=(ans*st[i].size())%mod;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}