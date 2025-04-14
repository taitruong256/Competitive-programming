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
struct sgm{ll x1, y1, x2, y2;};
sgm dt[2005];
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
    set<ll>x, y;
    map<ll, ll> idx, idy;
    for (ll i=1; i<=n; i++)
    {
        cin>>dt[i].x1>>dt[i].y1>>dt[i].x2>>dt[i].y2;
        if (dt[i].x1>dt[i].x2) swap(dt[i].x1, dt[i].x2);
        if (dt[i].y1>dt[i].y2) swap(dt[i].y1, dt[i].y2);
        x.insert(dt[i].x1); x.insert(dt[i].x2);
        y.insert(dt[i].y1); y.insert(dt[i].y2);
    }

    for (ll i=1; i<=m; i++)
    {
        cin>>bo[i].first>>bo[i].second;
        x.insert(bo[i].first);
        y.insert(bo[i].second);
    }
    ll id=0;
    for (auto it: x) idx[it]=++id;
    id=0;
    for (auto it: y) idy[it]=++id;
    // for (auto it: x) cout<<it<<" "; cout<<endl;
    // for (auto it: y) cout<<it<<" "; cout<<endl<<endl;


    memset(canhdong, 0, sizeof(canhdong));
    for (ll k=1; k<=n; k++)
    {
        ll xx1=idx[dt[k].x1], yy1=idy[dt[k].y1], xx2=idx[dt[k].x2], yy2=idy[dt[k].y2];
        if (xx1==xx2) 
            for (ll i=yy1*2; i<=yy2*2; i++) canhdong[xx1*2][i]=1;
        else
            for (ll i=xx1*2; i<=xx2*2; i++) canhdong[i][yy1*2]=1;
        // cout<<xx1<<" "<<yy1<<" "<<xx2<<" "<<yy2<<endl;
    }
    for (ll k=1; k<=m; k++)
    {
        ll xx=idx[bo[k].first]*2, yy=idy[bo[k].second]*2;
        canhdong[xx][yy]=2;
    }
    // for (ll i=1; i<=20; i++)
        // for (ll j=1; j<=20; j++) cout<<canhdong[i][j]<<" \n"[j==20];

    ll ans=0;
    for (ll i=1; i<=m; i++) 
    {
        ll x=bfs(idx[bo[i].first]*2, idy[bo[i].second]*2); 
        ans=max(ans, x);
    }
    cout<<ans<<endl;
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