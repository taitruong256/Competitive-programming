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
#define ll long long
ll power[20], digit[20];

void solve()
{
    ll n; cin>>n;
    ll block=lower_bound(digit, digit+18, n)-digit;
    ll l=power[block-1], r=power[block]-1, mn=power[block-1], pos=digit[block-1], index=0;
    ll ans=l; // cout<<l<<" "<<r<<" "<<pos<<"       ";
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if ((mid-mn)*block+pos+1<=n) ans=mid, l=mid+1;
        else r=mid-1;
    }

    l=power[block-1], r=power[block]-1, mn=power[block-1], pos=digit[block-1], index=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if ((mid-mn)*block+pos+1<=n) 
        {
            if ((mid-mn)*block+pos+1>index) index=(mid-mn)*block+pos+1;
            l=mid+1;
        }
        else r=mid-1;
    }
    string number=to_string(ans);       //cout<<ans<<" "<<index<<endl;
    cout<<number[n-index]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    power[0]=1;
    for (ll i=1; i<18; i++) power[i]=power[i-1]*10;
    digit[0]=0;
    for (ll i=1; i<18; i++) digit[i]=digit[i-1]+(power[i]-power[i-1])*i;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}