/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans=0;
ll a[1<<1];

void dfs(ll x)
{     
    if (x>(1<<(n+1))-1) return;   //cout<<x<<endl;
    dfs(x*2);
    dfs(x*2+1);
    ans+=max(a[2*x], a[2*x+1])-min(a[2*x], a[2*x+1]);
    a[x]+=max(a[2*x], a[2*x+1]);
}

void solve()
{
    cin>>n;
    memset(a, 0, sizeof(a));
    for (ll i=2; i<=(1<<(n+1))-1; i++) cin>>a[i];
    dfs(1);  
    cout<<ans;
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
