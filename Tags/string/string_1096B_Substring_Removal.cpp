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
    string s; cin>>s;
    ll l=0, r=0;
    for (ll i=0; i<n; i++) if (s[i]==s[0]) ++l; else break;
    for (ll i=n-1; i>=0; i--) if (s[i]==s[n-1]) ++r; else break;
    if (s[0]==s[n-1]) cout<<((l+1)*(r+1))%998244353;
    else cout<<l+r+1;
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