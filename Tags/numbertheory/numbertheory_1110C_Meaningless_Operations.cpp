/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll uoc_max(ll n)
{
    ll ans=1;
    for (ll i=2; i*i<=n; i++) if (n%i==0) ans=max({ans, i, n/i});
    return ans;
}

void solve()
{
    ll n; cin>>n;
    ll power=1;
    while (power<=n) power*=2;
    ll ans=0;
    if (n==power-1) cout<<uoc_max(n)<<endl;
    else cout<<power-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}