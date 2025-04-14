/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
 
void solve()
{
    ll n, q; cin>>n>>q;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    deque<ll> dq;
    for (ll i=1; i<=n; i++) dq.push_back(a[i]);
 
    pair<ll, ll> ans[3*n+5];
    for (ll i=1; i<=n+n; i++)
    {
        ll x=dq.front(); dq.pop_front();
        ll y=dq.front(); dq.pop_front();
        ans[i]={x, y};
        if (x>y)
        {
            dq.push_front(x);
            dq.push_back(y);
        }
        else
        {
            dq.push_front(y);
            dq.push_back(x);
        }
    }
   
    for (ll i=1; i<=q; i++)
    {
        ll m; cin>>m;
        if (m<=n) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        else 
        {
            m-=n;
            m%=(n-1);
            cout<<ans[n+m].first<<" "<<ans[n+m].second<<endl;
        }
    }
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
