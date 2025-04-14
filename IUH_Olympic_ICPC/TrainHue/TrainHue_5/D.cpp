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
    ll n, k; cin>>k>>n;
    for (ll i=n-k+1; i<=n+k-1; i++) if (i>=-1e6 && i<=1e6) cout<<i<<" ";
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
