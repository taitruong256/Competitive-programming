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
    ll a[n+5], f[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    f[1]=a[1];
    f[2]=a[2];
    priority_queue<ll> pq;
    for (ll i=3; i<=n; i++)
    {
        pq.push(f[i-2]);
        f[i]=pq.top()+a[i];
    }
    // for (ll i=1; i<=n; i++) cout<<f[i]<<" ";
    cout<<*max_element(f+n, f+n+1);
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