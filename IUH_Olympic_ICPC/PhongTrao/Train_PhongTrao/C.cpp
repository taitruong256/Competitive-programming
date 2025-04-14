/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=-1;
ll n, k; 
ll a[1005];

void check(ll x)
{
    ll b[1005];
    for (ll i=1; i<=n; i++) b[i]=a[i];
    for (ll i=x; i<=n; i+=k) b[i]=0;
    for (ll i=x; i>=1; i-=k) b[i]=0;

    // for (ll i=1; i<=n; i++) cout<<b[i]<<" "; cout<<endl;
    ll cnt1=0, cnt2=0;
    for (ll i=1; i<=n; i++) 
        if (b[i]==1) ++cnt1;
        else if (b[i]==-1) ++cnt2;
    //cout<<cnt1<<" "<<cnt2<<endl;
    ans=max(ans, abs(cnt1-cnt2));
}   

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) check(i);
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