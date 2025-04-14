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
    ll a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll index=0;
    for (ll i=n; i>=1; i--) if (a[i]!=0)
    {
        index=i;
        break;
    }
    // cout<<index<<endl;
    ll sum=0;
    for (ll i=index; i>=1; i--)
    {
        sum+=a[i];
        if (sum>=0)
        {
            if (sum==0 && i!=1)
            {
                cout<<"No\n";
                return;
            }
            else if (sum>0)
            {
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
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