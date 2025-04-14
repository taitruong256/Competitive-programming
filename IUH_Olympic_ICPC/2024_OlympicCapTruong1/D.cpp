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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, m, q, k, secret[200005], d[200005]; 
vector<ll> adj[200005], val;

void bfs()
{
    queue<ll> que;
    for (ll i=1; i<=q; i++) que.push(secret[i]), d[secret[i]]=0;
    while (!que.empty())
    {
        ll u=que.front(); que.pop();
        for (auto v: adj[u]) if (d[v]==-1)
        {
            d[v]=d[u]+1;
            que.push(v);
        }
    }
}

void solve()
{
    cin>>n>>m>>q>>k;
    for (ll i=1; i<=q; i++) cin>>secret[i];
    for (ll i=1; i<=n; i++) d[i]=-1;
    for (ll i=0; i<m; i++) 
    {
        ll u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll sum=0, x=0;
    for (ll i=1; i<=2000; i++) 
    {
        sum+=x;
        val.push_back(sum);
        x+=k;
        
    }
    bfs();
    // for (auto i: val) cout<<i<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<d[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) 
    {
        ll pos=lower_bound(val.begin(), val.end(), d[i])-val.begin();
        cout<<pos<<" ";
        // cout<<pos<<" "<<val[pos]<<endl;
    }
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