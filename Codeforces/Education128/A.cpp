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
    ll tam[100];
    memset(tam, 0, sizeof(tam));
    ll a, b, c, d; cin>>a>>b>>c>>d;
    for (ll i=a; i<=b; i++) ++tam[i];
    for (ll i=c; i<=d; i++) ++tam[i];
    for (ll i=1; i<=50; i++) if (tam[i]>1)
    {
        cout<<max(a, c)<<endl;
        return;
    }
    cout<<a+c<<endl;
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