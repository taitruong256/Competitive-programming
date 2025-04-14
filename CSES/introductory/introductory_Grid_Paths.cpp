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
ll ans=0;
bool vis[10][10];
string s;

bool isvalid(ll x, ll y)
{
    if (vis[x][y]==false && 1<=x && x<=7 && 1<=y && y<=7) return true;
    return false;
}

void dfs(ll x, ll y, ll cnt)
{
    if (cnt==48 || (x==7 && y==1))
    {
        if (x==7 && y==1 && cnt==48) ++ans; 
        return;
    }        

    vis[x][y]=true;
    char c=s[cnt];
    if ((c=='?' || c=='U') && isvalid(x-1, y) && !(!isvalid(x-2, y) && isvalid(x-1, y-1) && isvalid(x-1, y+1))) dfs(x-1, y, cnt+1);
    if ((c=='?' || c=='D') && isvalid(x+1, y) && !(!isvalid(x+2, y) && isvalid(x+1, y-1) && isvalid(x+1, y+1))) dfs(x+1, y, cnt+1);
    if ((c=='?' || c=='L') && isvalid(x, y-1) && !(!isvalid(x, y-2) && isvalid(x+1, y-1) && isvalid(x-1, y-1))) dfs(x, y-1, cnt+1);
    if ((c=='?' || c=='R') && isvalid(x, y+1) && !(!isvalid(x, y+2) && isvalid(x-1, y+1) && isvalid(x+1, y+1))) dfs(x, y+1, cnt+1);
    vis[x][y]=false;
}

void solve()
{
    cin>>s;
    for (ll i=0; i<=8; i++)
        for (ll j=0; j<=8; j++) vis[i][j]=false;
    dfs(1, 1, 0);
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