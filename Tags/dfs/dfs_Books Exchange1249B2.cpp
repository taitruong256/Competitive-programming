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
    ll a[n+5], ans[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    bool visited[n+5];
    memset(visited, false, sizeof(visited));
    for (ll i=1; i<=n; i++) if (visited[i]==false)
    {
        ll u=i, cnt=0;
        while (visited[u]==false)
        {
            ++cnt;
            visited[u]=true;
            u=a[u];
        }
        u=i;
        do
        {
            ans[u]=cnt;
            u=a[u];
        }
        while (u!=i);
    }

    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
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
