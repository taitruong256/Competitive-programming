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
    ll n, x; cin>>n>>x;
    ll a[n+5], s[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1, greater<ll>());
    s[0]=0;
    for (ll i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    //for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;

    for (ll k=0; k<=n; k++) 
    {
        ll sum=0;
        a[k]+=x;
        for (ll i=1; i<=n; i++) if (a[i]>0) sum+=a[i];
        if (sum<=0)
        {
            if (k==0) cout<<0<<" ";
            else cout<<a[1]<<" ";
        }
        else 
        {
            cout<<sum<<" ";
        }
    }
    cout<<endl;
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