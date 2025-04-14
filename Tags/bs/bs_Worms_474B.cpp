#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{           
    ll n; cin>>n;
    ll s[n+1];
    s[0]=0;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        s[i]=s[i-1]+x;
    }
    ll m; cin>>m;
    while (m--)
    {
        ll x; cin>>x;
        cout<<lower_bound(s, s+n, x)-s<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}