/*=====================================================================================
    Nothing is impossible, only you think it is impossible                 
            Try, try, try again until you succeed     
              Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll a[25], chinhhop[25];
ll ans=1e16;

void check()
{
    ll p[25];
    memset(p, 0, sizeof(p));
    for (int i=1; i<=n; i++) p[chinhhop[i]]+=a[i];
    ans=min(ans, (ll)*max_element(p+1, p+k+1)-(ll)*min_element(p+1, p+k+1) );
}

void __sinh(ll x)
{
    for (ll i=1; i<=k; i++)
    {
        chinhhop[x]=i;
        if (x==n) check();
        else __sinh(x+1);
    }
}

void solve()
{
    cin>>n>>k;       
    for (ll i=1; i<=n; i++) cin>>a[i];
    __sinh(1);
    cout<<ans;
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