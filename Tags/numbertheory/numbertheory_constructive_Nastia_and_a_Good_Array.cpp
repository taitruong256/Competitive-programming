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
    ll mn=1e18, pos=1;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<mn)
        {
            mn=a[i];
            pos=i;
        }
    }
    cout<<n-1<<endl;
    for (ll i=1; i<=n; i++)
    {
        if (i==pos) continue;
        cout<<pos<<" "<<i<<" "<<mn<<" "<<mn+abs(i-pos)<<endl;
    }
    // for (ll i=1; i<=n; i++) cout<<a[i]<<" "; cout<<endl;
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