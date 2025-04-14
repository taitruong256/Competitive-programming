#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll d[200005][32];
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
void solve()
{  
    ll l,r; cin>>l>>r;
    ll ans=200005;
    
    for (ll i=0; i<32; i++) ans=min(ans, d[r][i]-d[l-1][i]);
    cout<<ans<<endl;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    
    for (ll j=0; j<32; j++) d[0][j]=0;
    for (ll i=1; i<200005; i++)
        for (ll j=0; j<32; j++)
        {
            d[i][j]=d[i-1][j];
            if ((i & (1LL<<j))==0) ++d[i][j];
        }
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}