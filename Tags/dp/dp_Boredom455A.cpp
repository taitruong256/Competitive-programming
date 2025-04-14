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
    ll n; cin>>n; 
    ll f[100005];
    memset(f, 0, sizeof(f));
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        f[x]+=x;
    }
    for (ll i=2; i<=100000; i++) f[i]=max(f[i-1], f[i-2]+f[i]);
    cout<<f[100000];
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