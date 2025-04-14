/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

ll doi(ll k, ll n)
{
    if (k==n+1) return 1;
    else return k+1;
}

void solve()
{
    ll n, k; cin>>n>>k;
    if (n==k)
    {
        cout<<-1;
        return;
    }
    ll ans[n+5];
    for (ll i=1; i<=n; i++) ans[i]=0;
    for (ll i=2; i<=k+1; i++) ans[i]=i;
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
    ans[1]=k+2;
    for (ll i=1; i<=n; i++) if (ans[i]==0) ans[i]=i+1;
    for (ll i=1; i<=n; i++) if (ans[i]!=n+1) cout<<ans[i]<<" "; else cout<<1<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}