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
ll canhdong[2005][2005];
ll cnt=0, len=1, phai=2, xuong=3, trai=4, dx[]={0, -1, 0, 1, 0}, dy[]={0, 0, 1, 0, -1};
pair<ll, ll> bo[2005];

ll bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    cnt=0;
    q.push({x, y});
    while (!q.empty())
    {
        pair<ll, ll> f=q.front(); q.pop();
        ll x=f.first, y=f.second;
        for (ll i=1; i<=4; i++)
        {
            ll xi=x+dx[i], yi=y+dy[i];   
            if (xi<0 || yi<0 || xi>2000 || yi>2000 || canhdong[xi][yi]==1) continue;
            if (canhdong[xi][yi]==2) ++cnt;
            q.push({xi, yi});
            canhdong[xi][yi]=1;
        }
    }
    return cnt;
}

void solve()
{
    ll n, m; cin>>n>>m;
    memset(canhdong, 0, sizeof(canhdong));
    for (ll i=1; i<=n; i++)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        if (x1>x2) swap(x1, x2);
        if (y1>y2) swap(y1, y2);
        if (x1==x2) 
            for (ll i=y1*2; i<=y2*2; i++) canhdong[x1*2][i]=1;
        else
            for (ll i=x1*2; i<=x2*2; i++) canhdong[i][y1*2]=1;
    }

    for (ll i=1; i<=m; i++)
    {
        ll x, y; cin>>x>>y;
        x*=2; y*=2;
        bo[i].first=x; bo[i].second=y;
        canhdong[x][y]=2;
    }

    ll ans=0;
    for (ll i=1; i<=m; i++) 
    {
        ll x=bfs(bo[i].first, bo[i].second); 
        ans=max(ans, x);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}