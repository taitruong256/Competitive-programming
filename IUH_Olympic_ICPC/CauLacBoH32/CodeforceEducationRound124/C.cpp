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
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>b[i];

    ll t1=1e18, t2=1e18, t3=1e18, t4=1e18;
    for (ll i=1; i<=n; i++) t1=min(t1, abs(a[i]-b[1]));
    for (ll i=1; i<=n; i++) t2=min(t2, abs(a[i]-b[n]));
    for (ll i=1; i<=n; i++) t3=min(t3, abs(a[1]-b[i]));
    for (ll i=1; i<=n; i++) t4=min(t4, abs(a[n]-b[i]));
    //cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;

    ll ans=t1+t2+t3+t4;
    ans=min(ans, abs(a[1]-b[1])+abs(a[n]-b[n]));
    ans=min(ans, abs(a[1]-b[n])+abs(a[n]-b[1]));
    ans=min(ans, abs(a[1]-b[1])+t2+t4);
    ans=min(ans, abs(a[n]-b[n])+t1+t3);
    ans=min(ans, abs(a[1]-b[n])+t1+t4);
    ans=min(ans, abs(a[n]-b[1])+t2+t3);
    cout<<ans<<endl;
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