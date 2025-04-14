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
Cho cay n dinh n-1 canh. Mot nhanh la mot cay co 3 dinh. Ban hay cat mot so canh sao cho mot dinh thuoc dung mot nhanh.
Co co dap in ra so dinh, cac dinh. Nguoc lai in ra -1.

Input
4
9
1 2
4 3
7 9
5 4
4 6
3 2
8 7
1 7
6
1 2
1 3
4 3
1 5
6 1
6
1 2
3 2
3 4
4 5
6 5
5
1 3
5 3
5 2
3 4
Output
2
2 8 
-1
1
3 
-1

Y tuong: tham lam
Neu dinh u co chinh xac 3 con, cat canh (u, par[u])
Nguoc lai: (co 1 hoac 2 con) thi de don len cho cha roi cat.
*/

ll n;
vector<pair<ll, ll>> adj[200005];
vector<ll> ans;

ll dfs(ll u, ll p)
{
    ll tot=1;
    for (auto [v, id]: adj[u]) if (v!=p)
    {
        ll cur=dfs(v, u);
        if (cur==3) ans.push_back(id);
        else tot+=cur;
    }
    return tot;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    ll cnt=dfs(1, 0);
    if (cnt!=3) cout<<-1<<endl;
    else 
    {
        cout<<ans.size()<<endl;
        for (auto i: ans) cout<<i<<" ";
        cout<<endl;
    }

    ans.clear();
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