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
Bai toan: 
Cho mot cay n dinh n-1 canh, moi dinh co gia tri a[i].
Moi thao tac duoc chon dinh u va gia tri c, thay the tat ca cay con cua u bang a[i]=a[i]^c chi phi la c*sz[u]
Tinh chi phi toi thieu de tat ca cac dinh co gia tri bang nhau, voi dinh i lam goc cua cay 

Test:
Input
2
4
3 2 1 0
1 2
2 3
2 4
1
100
Output
8 6 12 10 
0 
In the first test case, to find m1 we root the tree at vertex 1
.

In the first spell, choose v=2 and c=1. After performing the spell, a will become [3,3,0,1]. The cost of this spell is 3
In the second spell, choose v=3 and c=3. After performing the spell, a will become [3,3,3,1]. The cost of this spell is 3
In the third spell, choose v=4 and c=2. After performing the spell, a will become [3,3,3,3]. The cost of this spell is 2
Now all the values in array a are equal, and the total cost is 3+3+2=8.

Y tuong:
Goi p[u] la cha cua u. Bai toan yeu cau dua tat ca gia tri bang nhau => a[u]=a[p[u]]=a[p[p[u]]]=...=a[root]
Vay nen chi phi toi thieu (duy nhat) la: tong(a[u]*a[p[u]])*sz[u]
Dung ky thuat dp on tree - solve for all root de tim dap an cho cac goc khac (luu y chi co sz[u] va sz[v] thay doi)

*/


ll n, a[200005], sz[200005], ans, res[200005], par[200005];
vector<ll> adj[200005];

void dfs(ll u, ll p)
{
    sz[u]=1;
    for (auto v: adj[u]) if (v!=p)
    {
        par[v]=u;
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void reroot(ll u, ll p)
{
    res[u]=ans;
    for (auto v: adj[u]) if (v!=p)
    {
        ll pre=ans;
        ans-=(a[u]^a[v])*sz[v];
        sz[u]=n-sz[v];
        sz[v]=n;
        ans+=(a[u]^a[v])*sz[u];
        reroot(v, u);
        sz[v]=n-sz[u];
        sz[u]=n;
        ans=pre;
    }
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    ans=0;
    for (ll i=2; i<=n; i++) ans+=(a[i]^a[par[i]])*sz[i];
    reroot(1, 0);
    for (ll i=1; i<=n; i++) cout<<res[i]<<" "; 
    cout<<endl;

    for (ll i=1; i<=n; i++) adj[i].clear();
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