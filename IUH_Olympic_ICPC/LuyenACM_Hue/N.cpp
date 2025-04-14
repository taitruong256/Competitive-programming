/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll x)
{
    if (x<=5) return 100;
    else return 100+(x-5);
}

void solve()
{
    ll n; cin>>n;
    map<string, ll> cnt; 
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        ++cnt[s];
    }
    ll ans=0;
    for (auto it: cnt) ans+=phi(it.second);
    cout<<ans;
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