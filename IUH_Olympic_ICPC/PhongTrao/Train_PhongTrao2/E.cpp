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
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    if (n!=m || n==2) 
    {
        cout<<-1<<endl;
        return;
    }
    else 
    {
        ll sum=0;
        for (ll i=0; i<n; i++) sum+=a[i];
        cout<<sum*2<<endl;
        for (ll i=1; i<=n-1; i++) cout<<i<<" "<<i+1<<endl;
        cout<<n<<" "<<1<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}