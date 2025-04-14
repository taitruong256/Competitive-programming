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
    ll n, m; cin>>n>>m;
    ll sum=0, a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) sum+=a[i];

    sort(a+1, a+n+1, greater<ll>());
    //for (ll i=1; i<=n; i++) cout<<a[i]<<endl;
    bool ok=true;
    ll c=0;
    for (ll i=1; i<=n; i++) if ((a[i]/sum)>=1/(4*m)) c++;

    // cout<<sum/4<<endl;
    if (c>=m) cout<<"Yes";
    else cout<<"No";
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