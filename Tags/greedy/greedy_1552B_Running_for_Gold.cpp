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
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5][5];
    for (ll i=1; i<=n; i++)
        for (ll j=0; j<5; j++) cin>>a[i][j];
    ll ans=1;
    for (ll i=2; i<=n; i++)
    {
        ll cnt=0;
        for (ll j=0; j<5; j++) if (a[i][j]<a[ans][j]) ++cnt;
        if (cnt>=3) ans=i;
    }
    
    for (ll i=1; i<=n; i++)
    {
        ll cnt=0;
        for (ll j=0; j<5; j++) if (a[i][j]<a[ans][j]) ++cnt;
        if (cnt>=3)
        {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<ans<<endl;
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