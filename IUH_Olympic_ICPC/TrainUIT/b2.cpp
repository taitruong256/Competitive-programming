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
    for (ll i=1; i<=n; i++) cin>>a[i];
    a[0]=a[n+1]=0;
    ll ans=1;
    for (ll i=1; i<=n; i++)
    {                 cout<<i<<"  ";
        ll now=1;
        for (ll j=i-1; j>=1; j--)
        {                  //cout<<j<<" ";
            if (a[j-1]<=a[j] && a[j]<=a[j+1]) ++now;
            else break;
        }

        for (ll j=i+1; j<=n; j++)
        {       //cout<<j<<" ";
            if (a[j-1]>=a[j] && a[j]>=a[j+1]) ++now;
            else break;
        }
        cout<<now<<endl;
        ans=max(ans, now);
    }
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