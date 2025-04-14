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

void solve()
{
    ll n, m; cin>>n>>m;
    char a[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    char ans[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) ans[i][j]='.';
    
    for (ll i=1; i<=m; i++)
    {
        ll k=n;
        for (ll j=n; j>=1; j--) 
            if (a[j][i]=='o') k=j, ans[k--][i]='o';
            else if (a[j][i]=='*') ans[k--][i]='*';
    }
    
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) cout<<ans[i][j];
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}