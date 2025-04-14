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
    vector<ll> a;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    if (n%2==0)
    {
        for (ll i=0; i<n; i+=2) if (a[i]>a[i+1]) swap(a[i], a[i+1]);
        if (is_sorted(a.begin(), a.end())) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else 
    {
        for (ll i=1; i<n; i+=2) if (a[i]>a[i+1]) swap(a[i], a[i+1]);
        if (is_sorted(a.begin(), a.end())) cout<<"YES\n";
        else cout<<"NO\n";
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