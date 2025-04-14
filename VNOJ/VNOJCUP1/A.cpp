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
    vector<ll> a, b;
    for (ll i=0; i<n; i++) 
    {
        ll x;
        cin>>x;
        a.push_back(x);
    }
    for (ll i=0; i<n; i++) 
    {
        ll x;
        cin>>x;
        b.push_back(x);
    }
    vector<char> ans;
    if (a.back()==b.front())
    {
        for (ll i=0; i<a.size()-1; i++) cout<<'a';
        for (ll i=0; i<b.size(); i++) cout<<'b';
        cout<<'a';
    }
    else
    {
        for (ll i=0; i<a.size(); i++) cout<<"a";
        for (ll i=0; i<b.size(); i++) cout<<'b';
    }
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