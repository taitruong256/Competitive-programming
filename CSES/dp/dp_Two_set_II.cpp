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
const ll mod = 1e9+7;

ll binpow(ll x, ll n)
{         
    if (n==0) return 1;
    else 
    {
        ll tam=binpow(x, n/2);
        tam=(tam*tam)%mod;
        if (n%2==0) return tam;
        else return (tam*x)%mod;
    }
}

void solve()
{
    ll n; cin>>n;
    ll sum=n*(n+1)/2;
    ll dp[sum+5];
    if (sum%2==1)
    {
        cout<<0<<endl;
        return;
    }
    else
    {
        sum/=2; 
        for (ll i=0; i<=sum; i++) dp[i]=0;
        dp[0]=1;
        for (ll i=1; i<=n; i++)
            for (ll j=sum; j>=i; j--) dp[j]=(dp[j]+dp[j-i])%mod;
    }
    cout<<(dp[sum]*binpow(2, mod-2))%mod;
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