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
const ll mod = 998244353;

/*
Cho do thi co huong khong co chu trinh n dinh, moi dinh co s[i] canh, moi canh co trong so 0/1
void dfs(int i) {
    for(int j = 1; j <= S[i]; j++) {
        Z.push_back(W[i][j]); 
        dfs(L[i][j]); 
    }
}
Hoi co bao nhieu nghich the trong mang Z sau khi goi dfs(1)

Test
Input
5
2
4 0
3 1
0
1
2 0
2
3 1
5 1
0
output
4

In the end, Z=[0,1,0,1,1,0]. All of its inversions are (2,3), (2,6), (4,6), and (5,6)

Y tuong:
Dp tren DAG
Goi:
    dp[u]: so nghich the dinh u
    f0[u]: so luong so 0 them vao u 
    f1[u]: so luong so 1 them vao u 
    
    tu u den v:
    tam=dp[v]  //phai gan bien tam vi khi xong dfs dp[v], f0[v], f1[v] khong thay doi
    neu w==0:
        ++f0[v]
    nguoc lai:
        ++f1[v]
        dp[u]+=f0[v]     (so luong so 1 cua dinh u duong truoc 0 cua dinh v)
    dp[u]+=f1[u]*f0[v]
    f0[u]+=f0[v]
    f1[u]+=f1[v]
*/

vector<pair<ll, ll>> adj[200005];
ll n, s[200005];
ll dp[200005], f0[200005], f1[200005];
bool vis[200005];

void dfs(ll u)
{
    vis[u]=true;
    ll dpu=0, f0u=0, f1u=0;
    for (auto [v, w]: adj[u])
    {
        if (vis[v]==false) dfs(v);
        ll dpv=dp[v], f0v=f0[v], f1v=f1[v];
        if (w==0) f0v+=1, f0v%=mod;
        else dpu+=f0v, f1v+=1, dpu%=mod, f1v%=mod;
        dpu+=dpv;      dpu%=mod; 
        dpu+=f1u*f0v;  dpu%=mod;
        f0u+=f0v;      f0u%=mod;
        f1u+=f1v;      f1u%=mod;
    }
    dp[u]=dpu;
    f0[u]=f0u;
    f1[u]=f1u;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>s[i];
        for (ll j=1; j<=s[i]; j++)
        {
            ll u, w; cin>>u>>w;
            adj[i].push_back({u, w});
        }
    }
    dfs(1);
    cout<<dp[1];
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