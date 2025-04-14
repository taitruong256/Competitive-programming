/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    set<pair<ll, ll>> bandau, huongnoi;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        bandau.insert({x, i+1});
    }

    string s; cin>>s;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            pair<ll, ll> it=*bandau.begin();
            huongnoi.insert({it.first, it.second});
            bandau.erase(bandau.find({it.first, it.second}));
            cout<<it.second<<" ";
        }
        else
        {
            pair<ll, ll> it=*huongnoi.rbegin();
            huongnoi.erase(huongnoi.find({it.first, it.second}));
            cout<<it.second<<" ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}