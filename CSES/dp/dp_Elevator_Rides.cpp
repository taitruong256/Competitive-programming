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
#define inf 1e9

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll lim=(1<<n);
    vector<pair<ll, ll>> dp(lim);
    dp[0]={1, 0};

    for (ll i=1; i<lim; i++)
    {         
        pair<ll, ll> best={INT_MAX, INT_MAX};
        for (ll j=0; j<n; j++) if (i&(1<<j))
        {
            pair<ll, ll> now=dp[(1<<j)^i];     //  cout<<i<<" "<<(i^(1<<j))<<endl;
            if (now.second+a[j]<=m) now.second+=a[j];
            else now.first+=1, now.second=a[j];
            best=min(best, now);         
        }
        dp[i]=best;
    }
    // for (auto it: dp) cout<<it.first<<" "<<it.second<<endl;
    cout<<dp[(1<<n)-1].first;
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