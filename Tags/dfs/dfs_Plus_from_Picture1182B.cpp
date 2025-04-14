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
    ll n, m; cin>>n>>m;
    char a[n+5][m+5];
    bool visited[n+5][m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) visited[i][j]=false;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];
    
    for (ll i=2; i<=n-1; i++)
        for (ll j=2; j<=m-1; j++) 
            if (a[i][j]=='*' && a[i][j+1]=='*' && a[i][j-1]=='*' && a[i+1][j]=='*' && a[i-1][j]=='*')
            {                                          
                visited[i][j]=true;
                ll left=j, right=j, up=i, down=i;
                while (left>=1 && a[i][left]=='*') visited[i][left--]=true;
                while (right<=m && a[i][right]=='*') visited[i][right++]=true;  
                while (up>=1 && a[up][j]=='*') visited[up--][j]=true;
                while (down<=n && a[down][j]=='*') visited[down++][j]=true;

                // for (ll i=1; i<=n; i++)
                // {
                //     for (ll j=1; j<=m; j++) cout<<visited[i][j]<<" ";
                //     cout<<endl;
                // }

                for (ll i=1; i<=n; i++)
                    for (ll j=1; j<=m; j++) if (a[i][j]=='*' && visited[i][j]==false) 
                    {
                        cout<<"NO";
                        return;
                    }

                cout<<"YES";
                return;
            }
    
    cout<<"NO";
    return;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}
