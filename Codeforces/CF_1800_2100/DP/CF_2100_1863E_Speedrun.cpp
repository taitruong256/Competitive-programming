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
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Co mot tro choi gom n nhiem vu, nhiem vu i chi co the hoan thanh vao gio h[i] trong ngay, mot ngay co k gio.
Co m cap nhiem vu phu thuoc nhau (a[i], b[i]) tuc la a[i] phai hoan thanh truoc b[i]
Tim thoi gian hoan thanh tro choi nhanh nhat.

Test
Input
6
4 4 24
12 16 18 12
1 2
1 3
2 4
3 4
4 3 10
2 6 5 9
1 4
2 4
3 4
2 1 10
5 5
1 2
5 0 1000
8 800 555 35 35
5 0 10
3 2 5 4 7
3 2 5
4 3 2
1 2
2 3
Output
24
7
0
480
5
8

Giai thich:
In the first test case, quests 1 and 4 must be completed at the beginning of the 12-th hour of the day, 
but they cannot be completed during the same hour, because you also need to complete quests 2 
and 3 between them. You can do all this in 24 hours, though. To do so, you start at 12 hours of the first 
game day by completing the first quest. At 16 hours you complete quest 2. At 18 hours you complete quest 3. 
Finally at 12 hours of the second day you can complete quest 4. The total time elapsed (from the moment you 
completed the first quest and the moment you completed the last) is 24 hours.

In the third test case, you can complete the first quest and then complete the remaining quest right after. 
You start at 5 hours of the first day by completing the first quest. After this the second quest becomes available, 
you complete it as well. The total time elapsed is 0.

In the fourth test case, you can start with the third quest. You start at 555 hours of the first day and 
you can finish at 35 hours of the second day. The total time elapsed is 1035−555=480.

Y tuong:
Tim nhung dinh khong phu thuoc (deg[i]=0), sap sep theo thoi gian bat dau tang dan vao vector idx 
Dung dp tren DAG de tim thoi gian lau nhat de hoan thanh tat ca nhiem vu ma phu thuoc i, goi do la f[i]
ans=min(max(f[i-1]+k)-h[idx[i]])   // moi nhiem vu chi co the cong them k gio.   
*/



vector<ll> adj[200005];
ll n, m, k, h[200005], deg[200005], f[200005], mx=0, ans;
bool vis[200005];
vector<ll> idx;

void dfs(ll u)
{
    vis[u]=true;
    f[u]=h[u];
    for (ll v: adj[u])
    {
        if (vis[v]==false) dfs(v);
        f[u]=max(f[u], f[v]+(h[u]>h[v])*k);
        mx=max(mx, f[u]);
    }
}

void solve()
{
    cin>>n>>m>>k;
    for (ll i=1; i<=n; i++) cin>>h[i];
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        ++deg[v];
    }
    for (ll i=1; i<=n; i++) if (deg[i]==0) idx.push_back(i);
    sort(idx.begin(), idx.end(), [](ll x, ll y) {return h[x]<h[y];});
    for (ll i: idx) if (vis[i]==false) dfs(i), mx=max(mx, f[i]);

    ans=mx-h[idx[0]];      
    for (ll i=1; i<idx.size(); i++)
    {
        mx=max(mx, f[idx[i-1]]+k);
        ans=min(ans, mx-h[idx[i]]);     
    }
    cout<<ans<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear(), vis[i]=false, deg[i]=0, f[i]=0;
    ans=mx=0;
    idx.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}