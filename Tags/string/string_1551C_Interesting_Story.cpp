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
    string a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll ans=0;
    for (char c='a'; c<='e'; c++) 
    {
        vector<ll> b(n+5, 0);
        for (ll i=0; i<n; i++)
            for (char x:a[i]) b[i]+=x==c?1:-1;
        // for (ll i=0; i<n; i++) cout<<b[i]<<" "; cout<<endl;
        sort(b.begin(), b.begin()+n, greater<ll>());
        ll cnt=0, s=0;
        for (ll i=0; i<n; i++)
        {
            s+=b[i];
            if (s>0) ++cnt;
            else break;
        }
        ans=max(ans, cnt);
    }
    cout<<ans<<endl;
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