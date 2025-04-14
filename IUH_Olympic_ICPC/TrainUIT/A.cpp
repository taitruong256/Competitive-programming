/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n, k; cin>>n>>k;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    a[0]=a[n+1]=0;
    bool check[n+5];
    memset(check, false, sizeof(check));
    
    ll ans=a[k];
    check[k]=true;
    ll x=k, y=k;
    while (true)
    {
        --x; ++y;
        if (x<1 || y>n) break;
        if (a[x]==a[y]) ans+=a[x]*2;
        check[x]=true;
        check[y]=true;
    }
    // for (ll i=1; i<=n; i++) cout<<check[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) if (check[i]==false) ans+=a[i];
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