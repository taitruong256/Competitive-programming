/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, cnt;
bool visited[30][30];
string hor, ver;   //horizontal: ngang, vertical: doc

void dfs(ll x, ll y)
{     
    if (visited[x][y]==true) return;
    if (x<1 || x>n || y<1 || y>m) return;       //      cout<<x<<" "<<y<<endl;
    visited[x][y]=true;
    ++cnt;
    if (hor[x]=='<') dfs(x, y-1);
    if (hor[x]=='>') dfs(x, y+1);
    if (ver[y]=='^') dfs(x-1, y);
    if (ver[y]=='v') dfs(x+1, y);
}

void solve()
{
    cin>>n>>m;
    cin>>hor>>ver;
    hor=" "+hor; 
    ver=" "+ver;     

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++)
        {
            memset(visited, false, sizeof(visited));
            cnt=0;
            dfs(i, j);         
            if (cnt!=n*m) 
            {
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
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
