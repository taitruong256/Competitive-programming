/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, cnt;
int a[1005][1005];
bool visited[1005][1005];
int xx[4]={0, 1, 0, -1};
int yy[4]={-1, 0, 1, 0};
vector<int> ans;

void dfs(int x, int y) {
    visited[x][y] = true;
    ++cnt;
    for (int k = 0; k < 4; k++) 
    {
        int tx = x + xx[k], ty = y + yy[k];
        if (!visited[tx][ty] && !(a[x][y] & (1<<k))) dfs(tx, ty);
    }
}

void solve()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin>>a[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) visited[i][j]=false;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) if (visited[i][j]==false)
        {
            cnt=0;
            dfs(i, j);
            ans.push_back(cnt);
        }
    
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
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
