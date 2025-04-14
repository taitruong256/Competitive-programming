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
    ll a[]={0, 4, 8, 15, 16, 23, 42};
    ll pos[n+5];
    for (ll i=1; i<=n; i++) cin>>pos[i];
    for (ll i=1; i<=n; i++) pos[i]=lower_bound(a, a+6, pos[i])-a;

    ll dp[n+5];
    memset(dp, 0, sizeof(dp));
    for (ll i=1; i<=n; i++)
    {
        if (pos[i]==1) ++dp[1];
        else if (dp[pos[i]-1]>0)
        {
            ++dp[pos[i]];
            --dp[pos[i]-1];
        }
    }
    cout<<n-dp[6]*6;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_+1<<endl;
        solve();
    }
    return 0;
}

//taitruong256