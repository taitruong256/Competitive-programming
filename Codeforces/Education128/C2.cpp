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
    string s; cin>>s;
    ll n=s.size();
    s=" "+s;
    ll l[n+5], r[n+5];
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    ll zero=0;
    for (auto c: s) if (c=='0') ++zero;

    l[0]=0;
    for (ll i=1; i<=n; i++) l[i]=l[i-1]+(s[i]=='0'?1:-1);

    r[n+1]=0;
    for (ll i=n; i>=1; i--) r[i]=r[i+1]+(s[i]=='0'?1:-1);


    for (ll i=1; i<=n; i++) cout<<l[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<r[i]<<" "; cout<<endl;
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