/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    ll l=0, r=n+1;
    for (ll i=1; i<=n; i++) 
    {
        if (a[i]<i-1) break;
        r=i;
    }
    for (ll i=n; i>=1; i--)
    {
        if (a[i]<(n-i)) break;
        l=i;
    }
    
    if (l<=r) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_+1<<endl;
        solve();
    }
    return 0;
}

//taitruong256