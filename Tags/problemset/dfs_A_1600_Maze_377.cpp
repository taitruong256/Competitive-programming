/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
const ll maxn = 2e5+5;
ll n, m, k;
string c[505];
bool vis[505][505];

void dfs(ll x, ll y)
{
    if (k==0 || vis[x][y]==true || c[x][y]!='.' || x<1 || x>n || y<1 || y>m) return;
    vis[x][y]=true;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    if (k==0) return;
    c[x][y]='X';  
    --k;
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++) cin>>c[i], c[i]=" "+c[i];
    memset(vis, false, sizeof(vis));
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (k>0 && c[i][j]=='.') dfs(i, j);

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) cout<<c[i][j];
        cout<<endl;
    }
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