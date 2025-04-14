/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5], thieu[n+5];
    for (ll i=0; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=n; i++) cin>>b[i];
    for (ll i=0; i<=n; i++) thieu[i]=a[i]-b[i];

    ll ans=0;
    for (ll i=n; i>=0; i--)
    {
        if (thieu[i]<0)
        {
            thieu[i]=-thieu[i];
            ll dung=(thieu[i]+1)/2;
            ans+=dung;
            if (i==0 && dung>0) ans=-1;
            else thieu[i-1]-=dung;
        }
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