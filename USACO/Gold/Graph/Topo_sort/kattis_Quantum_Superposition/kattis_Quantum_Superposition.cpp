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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n1, n2, m1, m2, in1[1005], in2[1005];
vector<ll> adj1[1005], adj2[1005];
set<ll> st1[1005], st2[1005];

void solve()
{
    cin>>n1>>n2>>m1>>m2;
    for (ll i=0; i<m1; i++)
    {
        ll u, v; cin>>u>>v;
        adj1[u].push_back(v);
        ++in1[v];
    }

    for (ll i=0; i<m2; i++)
    {
        ll u, v; cin>>u>>v;
        adj2[u].push_back(v);
        ++in2[v];
    }
    
    queue<ll> q1;
    for (ll i=1; i<=n1; i++) if (in1[i]==0) q1.push(i);
    st1[1].insert(0);
    while (!q1.empty())
    {
        int u=q1.front(); q1.pop();
        for (auto v: adj1[u]) 
        {
            --in1[v];
            if (in1[v]==0) q1.push(v);
            for (auto x: st1[u])
                st1[v].insert(x+1);
        }
    }

    queue<ll> q2;
    for (ll i=1; i<=n2; i++) if (in2[i]==0) q2.push(i);
    st2[1].insert(0);
    while (!q2.empty())
    {
        int u=q2.front(); q2.pop();
        for (auto v: adj2[u]) 
        {
            --in2[v];
            if (in2[v]==0) q2.push(v);
            for (auto x: st2[u])
                st2[v].insert(x+1);
        }
    }

    set<ll> ans;
    for (auto i: st1[n1])
        for (auto j: st2[n2])
            ans.insert(i+j);
    
    ll q; cin>>q;
    while (q--)
    {
        ll x; cin>>x;
        if (ans.find(x)!=ans.end()) cout<<"Yes\n";
        else cout<<"No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}