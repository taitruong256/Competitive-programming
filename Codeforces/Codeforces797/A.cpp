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
    ll n, x, y, z; cin>>n;
    ll ans=n;
    for (ll i=n; i>=1; i--)
    {
        ll b=i;
        ll x=n-i;
        int a, c;
        if (x%2==0) a=x/2+1, c=x/2-1;
        else a=x/2+1, c=x/2;
        if (b>a && a>c)
        {
            x=a;
            y=b;
            z=c;
        }
    }
    cout<<n-y-z<<" "<<y<<" "<<z<<endl;
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