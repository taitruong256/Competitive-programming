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
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];
    ll cnt1=0, cnt2=0;
    for (ll i=1; i<=n; i++)
        if (a[i]>b[i]) ++cnt1;
        else if (b[i]>a[i]) ++cnt2;
    cout<<cnt1<<" "<<cnt2;
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

