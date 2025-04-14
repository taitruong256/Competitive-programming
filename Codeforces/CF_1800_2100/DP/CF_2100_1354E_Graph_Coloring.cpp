
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
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

/*
Cho do thi n dinh m canh. Hoi co the:
-To mau moi dinh thuoc {1, 2, 3}
-Tong so dinh co mau 1 = n1
-Tong so dinh co mau 2 = n2
-Tong so dinh co mau 3 = n3
-|col[u]-col[v]|=1

Test:
Input
6 3
2 2 2
3 1
5 4
2 5
Output
YES
112323

Input
5 9
0 2 3
1 2
1 3
1 5
2 3
2 4
2 5
3 4
3 5
4 5
Output
NO

Y tuong:
Neu ta gom cac dinh co mau 1 va 3 lai thi se thanh do thi luong phan. Moi dinh chan se ke dinh le, moi dinh le ke dinh chan.
Van de con lai la khi do thi co nhieu thanh phan lien thong, chon phan chan hay le de to mau 2.
==> Co the dung dp cai tui de tim. 
Goi dp[i][j]: co the gom cac dinh cua i thanh phan lien thong dau tien, co tong cong j dinh khong?
Thuc hien truy vet tuong tu dp cai tui. Nho luu lai cac dinh cua thanh phan lien thong thu i co mau nao de to mau khi truy vet.
*/

ll n, m, n1, n2, n3, col[5005], cnt, ans[5005];
vector<ll> adj[5005];
bool dp[5005][5005], trace[5005][5005];
vector<ll> tplt[5005][4];

bool bfs(ll u, ll c)
{
    queue<ll> q;
    q.push(u);
    col[u]=1;
    while (!q.empty())
    {
        ll u=q.front(); q.pop(); 
        tplt[cnt][col[u]].push_back(u);
        for (auto v: adj[u]) 
            if (col[v]==0)
            {
                col[v]=3-col[u];
                q.push(v);
            }
            else if (col[v]==col[u]) return false;
    }
    return true;
}

void calc_dp()
{
    dp[0][0]=1;
    for (ll i=1; i<=cnt; i++)
        for (ll j=0; j<=n2; j++) 
        {
            ll sz=tplt[i][1].size();
            if (j>=sz) 
            {
                dp[i][j]|=dp[i-1][j-sz];
                if (dp[i][j]==1) trace[i][j]=0;
            }
            if (dp[i][j]==1) continue;
            sz=tplt[i][2].size();
            if (j>=sz) 
            {
                dp[i][j]|=dp[i-1][j-sz];
                if (dp[i][j]==1) trace[i][j]=1;
            }
        }
}

void trace_dp(ll i, ll j)
{
    if (i==0 || j==0) return;
    if (trace[i][j]==0)
    {
        ll sz=tplt[i][1].size(); 
        for (ll x: tplt[i][1]) ans[x]=2;
        trace_dp(i-1, j-sz);
    }
    else 
    {
        ll sz=tplt[i][2].size();
        for (ll x: tplt[i][2]) ans[x]=2;
        trace_dp(i-1, j-sz);
    }
}

void solve()
{
    cin>>n>>m;
    cin>>n1>>n2>>n3;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i=1; i<=n; i++) if (col[i]==0) 
    {
        ++cnt;
        if (bfs(i, 1)==false)
        {
            cout<<"NO";
            return;
        }
    }

    calc_dp();
    if (dp[cnt][n2]==0)
    {
        cout<<"NO";
        return;
    }

    trace_dp(cnt, n2);
    ll m=0;
    for (ll i=1; i<=n; i++) if (ans[i]==0)
    {
        if (m<n1) ans[i]=1;
        else ans[i]=3;
        ++m;
    } 
    cout<<"YES\n";
    for (ll i=1; i<=n; i++) cout<<ans[i]; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}