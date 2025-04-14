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
Van de:
Co mot cay n dinh goc 1.
Hay dem so cap (x, y) sao cho x khong phai to tien cua y va y khong phai to tien cua x

sol:
b1: dung dfs tinh sz[u] so luong nut con cua tung nut u
b2: dung dfs tinh so cap thoa man trong cay con goc u, co k con da duoc ghep:
    -neu sz[mx]-k<=sum-sz[mx]: co (sum-k)/2 cap co the ghep (sz[mx]-k vi k con da duoc ghep truoc do)
    -nguoc lai: 
        +co sum-sz[mx] cap co the ghep them vao (vi sz[mx]-k>sum-sz[mx])
        +de quy toi cay con co sz lon nhat 
*/

vector<ll> adj[200005];
ll sz[200005], ans=0;

void dfs(ll u, ll p)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=p)
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void calc(ll u, ll p, ll k)
{
    ll sum=0, mx=-1;
    for (auto v: adj[u]) if (v!=p)
    {
        sum+=sz[v];
        if (mx==-1 || sz[v]>sz[mx]) mx=v;
    }
    if (mx==-1) return;
    if (sz[mx]-k<=sum-sz[mx])  
    {
        ans+=(sum-k)/2;
        return;
    }
    ans+=sum-sz[mx];
    calc(mx, u, max(0LL, k+sum-sz[mx]-1));
}

void solve()
{
    ll n; cin>>n;
    for (ll i=2; i<=n; i++)
    {
        ll p; cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(1, 0);
    calc(1, 0, 0);
    cout<<ans<<endl;

    ans=0;
    for (ll i=1; i<=n; i++) adj[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}