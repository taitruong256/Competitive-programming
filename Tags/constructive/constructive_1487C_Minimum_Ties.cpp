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
    ll n; cin>>n;
    if (n%2==1)
    {
        for (ll i=1; i<=n; i++)
            for (ll j=i+1; j<=n; j++)
                if (j-i<=n/2) cout<<1<<" ";
                else cout<<-1<<" ";
        cout<<endl;
    }
    else
    {
        for (ll i=1; i<=n; i++)
            for (ll j=i+1; j<=n; j++) 
                if (j-i<n/2) cout<<1<<" ";
                else if (j-i==n/2) cout<<0<<" ";
                else cout<<-1<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}