/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ll;

void solve()
{
    ll n; cin>>n;
    ll ans=1, m=n;
    for (ll i=2; i*i<=m; i++) if (m%i==0)
    {
        while (m%i==0) m/=i;
        ans*=i;
    }
    if (m>1) ans*=m;
    ll cnt=0, p=ans;

    while (p%n!=0) p*=p, ++cnt;
    if (n!=p) ++cnt;
    cout<<ans<<" "<<cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}