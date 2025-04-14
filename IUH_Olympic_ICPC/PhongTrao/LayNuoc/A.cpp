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
    bool danhdau[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll ans=a[k];
    ll x=k, y=k;
    memset(danhdau, false, sizeof(danhdau));
    danhdau[k]=true;
    while (true)
    {
        --x; ++y;
        if (x<1 || y>n) break;
        danhdau[x]=true;
        danhdau[y]=true;
        if (a[x]==1 && a[y]==1) ans+=2;
    }
    for (ll i=1; i<=n; i++) if (danhdau[i]==false) ans+=a[i];
    // for (ll i=1; i<=n; i++) cout<<danhdau[i]<<" "; cout<<endl;
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