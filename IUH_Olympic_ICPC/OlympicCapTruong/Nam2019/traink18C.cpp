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
 
ll locate(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a=y1-y2, b=x2-x1;
    ll c=-a*x2-b*y2;
    return a*x3+b*y3+c;
}
 
void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n-2; i++) cout<<"L";
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