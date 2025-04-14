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
    map<ll, ll> a;
    ll n, q; cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll sum=0, all=0;
    for (ll i=1; i<=n; i++) sum+=a[i];  // cout<<sum<<endl;
    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll pos, x; cin>>pos>>x;
            if (all==0) 
            {
                sum-=a[pos];
                a[pos]=x;
                sum+=x;
            }
            else 
            {
                if (a[pos]==0)
                {
                    sum-=all;
                    a[pos]=x;
                    sum+=x;
                }
                else
                {
                    sum-=a[pos];
                    a[pos]=x;
                    sum+=x;
                }
            }
            cout<<sum<<endl;
        }
        else
        {
            ll x; cin>>x;
            a.clear();
            all=x;
            sum=x*n;
            cout<<sum<<endl;
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