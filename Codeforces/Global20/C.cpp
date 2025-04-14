/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    ll mx=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) mx=max(a[i], mx);
    ll l=1, r=n;
    ll ans=0;
    while (l<r && a[l]!=a[l+1]) ++l;
    while (l<r && a[r]!=a[r-1]) --r;
    // cout<<l<<" "<<r<<endl<<endl;
    while (l+2<r)
    { 
        // cout<<l<<" "<<r<<endl;
        
        if (l+2==r) break;
        if (l+2<r)
        {
            a[l+1]=a[l+2]=mx+1;
            mx++;
            l++; 
            ++ans;
        }
        if (l+2==r) break;
        cout<<l<<" "<<r<<endl;
        for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
        
        if (l+2<=r)
        {
            a[r-1]=a[r-2]=mx+1;
            mx++;
            r--;
            ++ans;
        }
        cout<<l<<" "<<r<<endl;
        for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
    }   
    // cout<<l<<" "<<r<<endl;
    if (l+2==r) ++ans;
    cout<<"ans = "<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}