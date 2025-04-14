/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    ll k, atk, health; cin>>k>>atk>>health;

    string ans="NO\n";
    for (ll i=0; i<=k; i++)
    {
        ll health_now=a+health*(k-i);
        ll atk_now=b+atk*i;
        ll x=ceil(1.0*c/atk_now);
        ll y=ceil(1.0*health_now/d);
        if (x<=y)
        {
            ans="YES\n"; //   cout<<a+atk*i<<"  "<<b+health*(k-i)<<endl;
            break;
        }
        
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}