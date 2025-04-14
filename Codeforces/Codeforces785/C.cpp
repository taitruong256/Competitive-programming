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
vector<ll> v;
ll dp[40005];
const ll mod=1e9+7;

void solve()
{
    ll n; cin>>n;
    cout<<dp[n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    for (ll i=1; i<=40000; i++)
    {
        string s=to_string(i);
        string t=s;
        reverse(s.begin(), s.end());
        if (s==t) v.push_back(i);
    }
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for (auto x: v)
        for (ll i=x; i<=40000; i++) dp[i]=(dp[i]+dp[i-x])%mod;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}