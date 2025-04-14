#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n, x, m; cin>>n>>x>>m;
    ll l=x, r=x;
    for (ll i=0; i<m; i++)
    {
        ll L, R; cin>>L>>R;
        if (max(l, L)<=min(r, R))
        {
            l=min(l, L);
            r=max(r, R);
        }
    }  
    cout<<r-l+1<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}