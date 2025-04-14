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
    map<ll, vector<ll>> mp;
    for (ll i=0; i<n; i++) cin>>a[i], mp[a[i]].push_back(i+1);
    for (auto it: mp) if (it.second.size()<2)
    {
        cout<<-1<<endl;
        return;
    }
    for (auto it: mp)
    {
        for (ll i=1; i<it.second.size(); i++) cout<<mp[it.first][i]<<" ";
        cout<<mp[it.first][0]<<" ";
    }
    cout<<endl;
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