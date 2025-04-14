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
    ll a[n+5], b[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) cin>>b[i];
    vector<ll> v, t;
    for (ll i=0; i<n; i++) 
        if (b[i]!=0) v.push_back(a[i]-b[i]);
        else t.push_back(a[i]);
    for (ll i=0; i<v.size(); i++) if (v[i]<0)
    {
        cout<<"NO\n";
        return;
    }
    if (v.size()==0)
    {
        cout<<"YES\n";
        return;
    }
    else
    {
        for (ll i=1; i<v.size(); i++) if (v[i]!=v[i-1])
        {
            cout<<"NO\n";
            return;
        }
        t.push_back(0);
        if (*max_element(t.begin(), t.end())<=v[0])
            cout<<"YES\n";
        else 
            cout<<"NO\n";
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