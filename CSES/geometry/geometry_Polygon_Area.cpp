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
const ll inf = 1e9;
struct point{ll x, y;};
 
 
void solve()
{
    ll n; cin>>n;
    point a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i].x>>a[i].y;
    ll ans=0;
    for (ll i=0; i<n; i++) ans+=(a[i].x*a[(i+1)%n].y)-(a[(i+1)%n].x*a[i].y);
    cout<<abs(ans)<<endl;
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