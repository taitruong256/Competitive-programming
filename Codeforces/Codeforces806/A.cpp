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

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];   cout<<n<<" "<<m<<endl;
    // string s=" ";
    // for (ll i=1; i<=m; i++) s.push_back('B');
    // for (ll i=1; i<=n; i++)
    // {
    //     if (s[a[i]]=='B') s[a[i]]='A';
    //     else s[m-a[i]+1]='A';
    // }
    // for (ll i=1; i<=m; i++) cout<<s[i];
    // cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}