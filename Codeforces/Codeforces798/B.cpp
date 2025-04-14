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
    ll a[n+5], ans[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    if (n==1)
    {
        cout<<-1<<endl;
        return;
    }

    bool dau[n+5];
    for (ll i=1; i<=n; i++) dau[i]=false;
    for (ll i=1; i<=n-2; i++)
    {
        for (ll j=1; j<=n; j++) if (dau[j]==false && j!=a[i])
        {
            ans[i]=j;
            dau[j]=true;
            break;
        }
    }
    for (ll i=n-1; i<=n; i++)
    {
        for (ll j=1; j<=n; j++) if (dau[j]==false)
        {
            ans[i]=j;
            dau[j]=true;
            break;
        }
    }
    if (ans[n-1]==a[n-1] || ans[n]==a[n]) swap(ans[n-1], ans[n]);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
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