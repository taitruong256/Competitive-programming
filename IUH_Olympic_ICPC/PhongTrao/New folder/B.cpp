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

void solve()
{
    ll n, m, a, b, c, d; cin>>n>>m>>a>>b>>c>>d;
    ll x=1, y=1;
    ll ans=0;
    while (true)
    {
        
        if (a==c || b==d) break;
        a+=x;
        b+=y;
        if (a==1 || a==n) x=-x;
        if (b==1 || b==m) y=-y;
        ++ans;
        // cout<<a<<" "<<b<<endl;
    }
    cout<<ans<<endl;
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