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
    ll n, x; cin>>n>>x;
    ll a[n+5], cnt[500005];
    for (ll i=0; i<n; i++) cin>>a[i];
    memset(cnt, 0, sizeof(cnt));
    for (ll i=0; i<n; i++) ++cnt[a[i]];
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        --cnt[a[i]];
        ans+=cnt[a[i]^x];
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}