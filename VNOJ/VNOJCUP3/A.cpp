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
    ll n, q; cin>>n>>q;
    while (q--)
    {
        pair<ll, ll> a, b, c, ans; cin>>a.first>>a.second>>b.first>>b.second;
        c=b;
        if (abs(a.first-b.first)+(abs(a.second-b.second))%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            ll x;
            if (a.first!=b.first)
            {
                x=abs(a.first-b.first);
                b.first=a.first;
            }
            if (a.second<b.second) b.second+=x;
            else b.second-=x;
            // cout<<b.first<<" "<<b.second<<endl;
            ll y=(a.second+b.second)/2;
            ans.second=a.second+y;
            if (a.first+y<=n) ans.first=a.first+y;
            else ans.first=a.first-y;
            cout<<ans.first<<" "<<ans.second<<endl;
            cout<<c.first<<" "<<c.second;
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