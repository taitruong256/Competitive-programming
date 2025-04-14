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
typedef int ll;
const ll maxn=1e6+5;
ll dp[maxn], a[maxn];

void solve()
{
    ll n; cin>>n;
    memset(dp, 0, sizeof(dp));
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        dp[a[i]]=1;
    }
    ll ans=1;
    for (ll i=0; i<n; i++)
    {
        ll x=a[i];
        for (ll j=x*2; j<maxn; j+=x) if (dp[j]>0) dp[j]=max(dp[j], dp[x]+1);
    }
    cout<<*max_element(dp, dp+maxn);
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