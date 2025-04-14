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
    ll n, m, r, c; cin>>n>>m>>r>>c;
    char a[100][100];
    ll d=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='B') ++d;
        }

    if (d==0)
    {
        cout<<-1<<endl;
        return;
    }
    if (a[r][c]=='B')
    {
        cout<<0<<endl;
        return;
    }
    for (int i=1; i<=n; i++) if (a[i][c]=='B') 
    {
        cout<<1<<endl;
        return;
    }
    for (int i=1; i<=m; i++) if (a[r][i]=='B') 
    {
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}