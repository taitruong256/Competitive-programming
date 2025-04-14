/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ans="NO";
ll n, d=0;
ll a[100];

void dfs(ll x, ll s)
{     
    if (x>n) return;
    if ((x==n && s%360==0) || ans=="YES")
    {
        ans="YES";
        return;
    }
    dfs(x+1, s+a[x]);
    dfs(x+1, s-a[x]);
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++) cin>>a[i];
    dfs(0, 0);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}