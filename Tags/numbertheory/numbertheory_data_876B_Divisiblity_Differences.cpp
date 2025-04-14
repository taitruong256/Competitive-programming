/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                   You may not be the best, but be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n, k, m; cin>>n>>k>>m;
    map<ll, vector<ll>> mp;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        mp[x%m].push_back(x);
    }
    for (auto it: mp) if (it.second.size()>=k)
    {
        cout<<"Yes\n";
        for (ll i=0; i<k; i++) cout<<mp[it.first][i]<<" ";
        return;
    }
    cout<<"No";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}