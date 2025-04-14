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
    ll n, k ; cin>>n>>k;
    ll a[n+5], b[k+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<k; i++) cin>>b[i];
    sort(b, b+k, greater<ll>());
    ll j=0;
    for (ll i=0; i<n; i++) if (a[i]==0) a[i]=b[j++];
    //for (ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    if (is_sorted(a, a+n)) cout<<"No";
    else cout<<"Yes";
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