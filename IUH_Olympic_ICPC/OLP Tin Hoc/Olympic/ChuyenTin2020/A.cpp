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
    ll a, b; cin>>a>>b;
    ll ans=0;
    for (ll i=1; i<=60; i++)
    {
        ll mu=(ll)pow(2, i);
        ll x=(a+mu-1)/mu*mu, y=(b/mu)*mu;
        if (x>y) break;
        ll cnt=(y-x)/mu+1;   //cout<<mu<<" "<<x<<" "<<y<<" "<<ans<<endl;
        ans+=cnt;
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
