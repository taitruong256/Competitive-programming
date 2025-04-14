/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n>>m;
    ll gia[1005];
    for (ll i=0; i<n; i++) cin>>gia[i];
    map<string, ll> cnt; 
    for (ll i=0; i<m; i++)
    {
        string t; cin>>t;
        cnt[t]++;
    }
    vector<ll> v;
    for (auto it: cnt) v.push_back(it.second);
    sort(v.begin(), v.end(), greater<ll>());
    //for (auto it: v) cout<<it<<" "; cout<<endl;
    sort(gia, gia+n);
    ll mx=0, mn=0;
    for (ll i=0; i<v.size(); i++) mn+=v[i]*gia[i];
    sort(gia, gia+n, greater<ll>());
    for (ll i=0; i<v.size(); i++) mx+=v[i]*gia[i];
    cout<<mn<<" "<<mx;
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