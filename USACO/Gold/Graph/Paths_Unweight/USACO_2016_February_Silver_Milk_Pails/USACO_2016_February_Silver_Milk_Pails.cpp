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
map<pair<ll, ll>, ll> cnt;
ll x, y, k, m;

void solve()
{
    setIO("pails");
    cin>>x>>y>>k>>m;
    cnt[{0, 0}]=0;
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    ll ans=1e18;
    while (!q.empty())
    {
        auto [xx, yy]=q.front(); q.pop(); 
        ans=min(ans, abs(m-(xx+yy)));
        if (cnt[{xx, yy}]>=k) continue;
        ll slx=min(xx, y-yy), sly=min(yy, x-xx);
        ll dx[]={xx, 0, x, xx, xx-slx, xx+sly};
        ll dy[]={0, yy, yy, y, yy+slx, yy-sly};
        for (ll i=0; i<6; i++)
        {
            ll new_xx=dx[i], new_yy=dy[i];
            if (cnt.find({new_xx, new_yy})==cnt.end())
            {
                q.push({new_xx, new_yy});
                cnt[{new_xx, new_yy}]=cnt[{xx, yy}]+1;
            }
        }
    }
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