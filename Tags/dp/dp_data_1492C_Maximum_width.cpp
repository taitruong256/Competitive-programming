/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    ll left[n+5], right[n+5];
    memset(left, 0, sizeof(left));
    memset(right , 0, sizeof(right));

    ll r=m-1;
    for (ll i=n-1; i>=0 && r>=0; i--) if (s[i]==t[r]) right[r--]=i;
    // for (ll i=0; i<m; i++) cout<<right[i]<<" "; cout<<endl;
    ll l=0;
    for (ll i=0; i<n && l<m; i++) if (s[i]==t[l]) left[l++]=i;
    // for (ll i=0; i<m; i++) cout<<left[i]<<" "; cout<<endl;
    ll ans=-1e9;
    for (ll i=0; i<m-1; i++) ans=max(ans, right[i+1]-left[i]);
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