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
    int d[200005], ans[200005];
    ll n, k, m; cin>>n>>k>>m; 
    for (ll i=0; i<n; i++)
    {
        ll l, r; cin>>l>>r;
        d[l]++;
        d[r+1]--;
    }

    for (ll i=1; i<200005; i++) d[i]+=d[i-1];

    for (ll i=0; i<200005; i++) if (d[i]>=k) ans[i]=1; else ans[i]=0;
    for (ll i=1; i<200005; i++) ans[i]+=ans[i-1];
    for (ll i=0; i<m; i++)
    {
        ll l, r; cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}