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
#define ngang 2
#define doc 1
const ll inf = 1e18;
const ll mod = 1e9+7;
map<ll, vector<ll>> adjx, adjy;
ll n, xs, ys, xt, yt;
map<pair<ll, ll>, ll> d;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

void solve()
{
    setIO("lasers");
    cin>>n>>xs>>ys>>xt>>yt;  
    for (ll i=0; i<n; i++)
    {
        ll x, y; cin>>x>>y;
        adjx[x].push_back(y);
        adjy[y].push_back(x);
    }

    queue<pair<ll, ll>> q;
    q.push({xs, doc});
    q.push({ys, ngang});
    d[{xs, doc}]=0;
    d[{ys, ngang}]=0;
    ll ans=1e18;
    while (!q.empty())
    {
        auto [toado, huong]=q.front(); q.pop();
        if (toado==xt && huong==doc) 
        {
            ans=min(ans, d[{xt, doc}]);
            continue;
        }
        if (toado==yt && huong==ngang) 
        {
            ans=min(ans, d[{yt, ngang}]);
            continue;
        }
        if (huong==doc)
        {
            for (auto y: adjx[toado])
            {   
                if (d.find({y, ngang})==d.end())
                {
                    d[{y, ngang}]=d[{toado, doc}]+1;
                    q.push({y, ngang});
                }
            }
        }
        else 
        {
            for (auto x: adjy[toado])
            {   
                if (d.find({x, doc})==d.end())
                {
                    d[{x, doc}]=d[{toado, ngang}]+1;
                    q.push({x, doc});
                }
            }
        }
    }
    if (ans==1e18) ans=-1;
    cout<<ans;
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