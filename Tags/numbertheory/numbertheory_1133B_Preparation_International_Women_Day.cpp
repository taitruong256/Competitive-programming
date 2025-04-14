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
    ll n, k; cin>>n>>k;
    map<ll, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        ++cnt[x%k];
    }
    ll ans=cnt[0]/2;   
    for (ll i=1; i<(k+1)/2; i++) ans+=min(cnt[i], cnt[k-i]);
    if (k%2==0) ans=cnt[k/2]/2;
    cout<<ans*2;
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