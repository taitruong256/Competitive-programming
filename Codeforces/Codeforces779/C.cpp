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
    ll n; cin>>n;
    ll a[2*n+10];
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll cnt=0, pos=1;
    for (ll i=1; i<=n; i++) if (a[i]==1) ++cnt, pos=i;
    if (cnt!=1)
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        for (ll i=1; i<pos; i++)
        {
            ++n;
            a[n]=a[i];
        }

        ll mx=1;
        for (ll i=pos+1; i<=n; i++) if (a[i]-a[i-1]>1)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}