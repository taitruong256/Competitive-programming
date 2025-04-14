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
    ll n; cin>>n;
    ll a[n+5]; 
    for (ll i=0; i<n; i++) cin>>a[i];
    ll m; cin>>m;
    ll b[m+5];
    for (ll i=0; i<m; i++) cin>>b[i];
    ll x=*max_element(a, a+n);
    ll y=*max_element(b, b+m);
    if (x>=y) cout<<"Alice\n";
    else cout<<"Bob\n";
    if (y>=x) cout<<"Bob\n";
    else cout<<"Alice\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}