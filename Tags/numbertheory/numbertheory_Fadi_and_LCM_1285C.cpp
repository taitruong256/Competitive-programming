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
    pair<ll, ll> t;
    t.first=1; t.second=n;
    ll ans=n;
    for (ll i=2; i*i<=n; i++) if (i*i!=n && n%i==0 && max(i, n/i)<ans && i/__gcd(i, n/i)*(n/i)==n)
    {
        ans=max(i, n/i);
        t.first=i;
        t.second=n/i;
    }
    cout<<t.first<<" "<<t.second<<endl;
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