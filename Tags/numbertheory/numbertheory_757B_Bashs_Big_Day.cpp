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
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll minprime[100005];
    for (ll i=1; i<=100000; i++) minprime[i]=0;
    minprime[1]=1e18;
    for (ll i=2; i*i<=100000; i++) if (minprime[i]==0)
        for (ll j=i; j<=100000; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=2; i<=100000; i++) if (minprime[i]==0) minprime[i]=i;

    map<ll, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        while (x>1)
        {
            ++cnt[minprime[x]];
            ll t=minprime[x];
            while (minprime[x]==t) x/=minprime[x];
        }
    }
    ll ans=1;
    for (auto it: cnt) ans=max(ans, it.second);
    cout<<ans;
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