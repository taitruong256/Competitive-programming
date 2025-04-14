/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, num;
ll ans[505][505];

void dfs(ll x, ll y, ll val)
{    
    if (num<0) return;      
    ans[x][y]=val;
    --num;
    if (y>1 && ans[x][y-1]==0) dfs(x, y-1, val);
    if (x<n && ans[x+1][y]==0) dfs(x+1, y, val);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<=n+1; i++)
        for (ll j=0; j<=n+1; j++) ans[i][j]=0;
        
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        ans[i][i]=x;
        num=x-1;
        dfs(i, i, x);
    }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=i; j++) cout<<ans[i][j]<<" ";
        cout<<endl;
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
