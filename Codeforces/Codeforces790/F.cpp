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
    ll n, k; cin>>n>>k;
    ll a[n+5];
    map<ll, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ++cnt[x];
    }
    vector<ll> v;
    for (auto it: cnt) if (it.second>=k) v.push_back(it.first);
    if (v.size()==0)
    {
        cout<<-1<<endl;
        return;
    }
    v.push_back(1e10);
    pair<ll, ll> ans={v[0], v[0]};
    ll d=1, dau=v[0];
    for (ll i=1; i<v.size(); i++)
    {
        if (v[i]-v[i-1]==1) ++d;
        else 
        {
            if (d>ans.second-ans.first)
            {
                ans.first=dau;
                ans.second=v[i-1];
            }
            d=1;
            dau=v[i];
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
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