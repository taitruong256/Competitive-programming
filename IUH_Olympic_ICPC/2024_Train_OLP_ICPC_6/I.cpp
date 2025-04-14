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

ll rows, cols, x, y, n, q;
pair<ll, ll> a[200005];
map<ll, vector<ll>> rockx, rocky;

void solve()
{
    cin>>rows>>cols>>x>>y;    
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i].first>>a[i].second;
        rockx[a[i].first].push_back(a[i].second);
        rocky[a[i].second].push_back(a[i].first);
    }
    for (auto &[x, y]: rockx) sort(y.begin(), y.end());
    for (auto &[x, y]: rocky) sort(y.begin(), y.end());

    cin>>q;
    while (q--)
    {
        char c; cin>>c;
        ll d; cin>>d;
        if (c=='L') 
        {
            ll pre_y_rock=1, pre_y_d=max(1LL, y-d);
            if (rockx.find(x)!=rockx.end())
            {
                auto it=lower_bound(rockx[x].begin(), rockx[x].end(), y);
                if (it!=rockx[x].begin()) pre_y_rock=*(--it)+1;
            }
            y=max(pre_y_d, pre_y_rock);
            cout<<x<<" "<<y<<endl;
        }
        else if (c=='R')
        {
            ll nxt_y_rock=cols, nxt_y_d=min(cols, y+d);
            if (rockx.find(x)!=rockx.end())
            {
                auto it=upper_bound(rockx[x].begin(), rockx[x].end(), y);
                if (it!=rockx[x].end()) nxt_y_rock=*(it)-1;
            }
            y=min(nxt_y_d, nxt_y_rock);
            cout<<x<<" "<<y<<endl;
        }
        else if (c=='U')
        {
            ll pre_x_rock=1, pre_x_d=max(1LL, x-d);
            if (rocky.find(y)!=rocky.end())
            {
                ll it=lower_bound(rocky[y].begin(), rocky[y].end(), x)-rocky[y].begin();
                if (it!=0) pre_x_rock=rocky[y][it-1]+1;
            }
            x=max(pre_x_d, pre_x_rock);
            cout<<x<<" "<<y<<endl;
        }
        else 
        {
            ll nxt_x_rock=rows, nxt_x_d=min(rows, x+d);
            if (rocky.find(y)!=rocky.end())
            {
                auto it=upper_bound(rocky[y].begin(), rocky[y].end(), x);
                if (it!=rocky[y].end()) nxt_x_rock=*(it)-1;
            }
            x=min(nxt_x_d, nxt_x_rock);
            cout<<x<<" "<<y<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}