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
    ll n, m, d; cin>>n>>m>>d;
    ll a[n*m+5];
    for (ll i=0; i<n*m; i++) cin>>a[i];
    sort(a, a+n*m);
    // for (ll i=0; i<n*m; i++) cout<<a[i]<<" "; cout<<endl;
    ll mid=n*m/2;
    ll ans=0;
    for (ll i=0; i<n*m; i++)
    {
        if ((a[i]-a[mid])%d!=0) 
        {
            cout<<"-1";
            return;
        }
        ans+=abs(a[i]-a[mid])/d;
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