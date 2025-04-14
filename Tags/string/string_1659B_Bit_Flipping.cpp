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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    s=" "+s;
    ll cnt[n+5], a[n+5];
    for (ll i=1; i<=n; i++) a[i]=s[i]-'0';
    for (ll i=1; i<=n; i++) cnt[i]=0;
    if (k%2==1)
        for (ll i=1; i<=n; i++) a[i]=1-a[i];
    
    for (ll i=1; i<=n-1; i++) if (a[i]==0 && k>0) cnt[i]=1, --k, a[i]=1;
    cnt[n]+=k;
    if (cnt[n]%2==1) a[n]=1-a[n];
    
    for (ll i=1; i<=n; i++) cout<<a[i]; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<cnt[i]<<" "; cout<<endl;
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