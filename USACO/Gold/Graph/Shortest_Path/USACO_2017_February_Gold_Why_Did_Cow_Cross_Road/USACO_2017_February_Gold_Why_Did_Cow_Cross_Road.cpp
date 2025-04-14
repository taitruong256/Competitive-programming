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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll n, t, a[105][105];
vector<pair<ll, ll>> adj[20005];

void solve()
{
    setIO("visitfj");
    cin>>n>>t;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) cin>>a[i][j];
    ll di[]={0, -1, -2, -3, 1, 0, -1, -2, 2, 1, 0, -1, 3, 2, 1, 0};
    ll dj[]={-3, -2, -1, 0, -2, -1, 0, 1, -1, 0, 1, 2, 0, 1, 2, 3};
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            for (ll k=0; k<16; k++)
            {
                ll new_i=i+di[k], new_j=j+dj[k];
                if (!(1<=new_i && new_i<=n && 1<=new_j && new_j<=n)) continue;
                ll u=(i-1)*n+j, v=(new_i-1)*n+new_j;
                adj[u].push_back({v, a[new_i][new_j]+3*t});
            }
            ll d=abs(n-i)+abs(n-j);
            if (d<3)
            {
                ll u=(i-1)*n+j, v=(n-1)*n+n;
                adj[u].push_back({v, d*t});
            }
        }

    vector<ll> d(n*n+5, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1]=0;
    while (!pq.empty())
    {
        auto [W, u]=pq.top(); pq.pop();
        if (W>d[u]) continue;
        for (auto [v, w]: adj[u])
        {
            if (d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
    cout<<d[n*n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}