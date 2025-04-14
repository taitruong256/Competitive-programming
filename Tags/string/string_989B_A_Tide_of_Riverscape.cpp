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
    map<ll, vector<char>> mp;
    mp.clear();
    ll n, p; cin>>n>>p;
    string s; cin>>s;
    for (ll i=0; i<p; i++)
        for (ll j=i; j<n; j+=p) mp[i].push_back(s[j]);
        
    for (ll i=0; i<p; i++)
    {
        ll zero=0, one=0;
        for (ll j=0; j<mp[i].size(); j++) if (s[i]=='0') ++zero; else ++one;
        if (one!=mp[i].size() && zero!=mp[i].size())
        {
            cout<<"No";
            return;
        }
    }
    cout<<s;
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