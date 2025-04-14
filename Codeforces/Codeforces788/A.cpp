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

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    a[n]=1e10;
    ll cnt=0;
    for (ll i=0; i<n; i++) 
    {
        if (a[i]>a[i+1]) 
        {
            if (a[i]>0) ++cnt;
            else --cnt;
            a[i]=-a[i];
        }
    }
    for (ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
    cout<<cnt<<endl;
    if (cnt==0 && is_sorted(a, a+n)) 
    {
        cout<<"YES\n";
        return;
    }
    if (cnt==-1 && a[n-1]<0)
    {
        a[n-1]=-a[n-1];
        if (is_sorted(a, a+n))
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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