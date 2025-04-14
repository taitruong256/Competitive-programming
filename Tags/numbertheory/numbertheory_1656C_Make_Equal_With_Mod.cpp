/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    map<ll, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ++cnt[x];
    }
    if (cnt[1]==0)
    {
        cout<<"YES\n";
        return;
    }
    vector<ll> v;
    for (auto it: cnt) v.push_back(it.first);
    for (ll i=0; i<v.size()-1; i++) if (v[i+1]-v[i]==1)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}