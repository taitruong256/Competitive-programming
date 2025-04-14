/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105], d[105];
ll n;

void dfs(ll l, ll r, ll deep) 
{                  //     cout<<l<<" "<<r<<" "<<deep<<endl;
    if (l>r) return;
    if (l==r)
    {
        d[l]=deep;
        return;
    }
    ll mx=l;
    for (ll i=l+1; i<=r; i++) if (a[i]>a[mx]) mx=i;
    d[mx]=deep;
    dfs(l, mx-1, deep+1);
    dfs(mx+1, r, deep+1);
    return;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    dfs(1, n, 0);
    for (ll i=1; i<=n; i++) cout<<d[i]<<" ";
    cout<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}
