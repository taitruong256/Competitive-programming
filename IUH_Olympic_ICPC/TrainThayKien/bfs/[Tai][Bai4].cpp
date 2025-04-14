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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    ll n; cin>>n;
    set<pair<ll, ll>> toado, vis;
    for (ll i=1; i<=n; i++)
    {
        ll x, y1, y2; cin>>x>>y1>>y2;
        for (ll j=y1; j<=y2; j++) toado.insert({x, j});
    }

    queue<pair<ll, ll>> q; 
    map<pair<ll, ll>, ll> step;
    q.push({x1, y1});
    while (!q.empty())
    {
        pair<ll, ll> f=q.front(); q.pop();
        ll x=f.first, y=f.second;
        if (x==x2 && y==y2) 
        {
            cout<<step[{x, y}]<<endl;
            return;
        }
        for (ll i=-1; i<=1; i++)
            for (ll j=-1; j<=1; j++) if (!(i==0 && j==0) && toado.count({x+i, y+j}))
            {
                ll xi=x+i, yi=y+j;
                if (!vis.count({xi, yi})) 
                {
                    vis.insert({xi, yi});
                    step[{xi, yi}]=step[{x, y}]+1;
                    q.push({xi, yi});
                }
            }
    }
    cout<<-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}